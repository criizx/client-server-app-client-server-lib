#include "server_lib.hpp"

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>

Server::Server(
    const std::string &ip, int port,
    const std::function<std::vector<char>(const std::vector<char> &)> &cb)
    : callback(cb) {
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  if (inet_pton(AF_INET, ip.c_str(), &server_address.sin_addr) <= 0) {
    throw std::invalid_argument("invalid ip address for listening");
  }
  setup_socket();
}

Server::Server(
    const std::string &listen_ip, int listen_port, const std::string &dest_ip,
    int dest_port,
    const std::function<std::vector<char>(const std::vector<char> &)> &cb)
    : destination_ip(dest_ip), destination_port(dest_port), callback(cb) {
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(listen_port);
  if (inet_pton(AF_INET, listen_ip.c_str(), &server_address.sin_addr) <= 0) {
    throw std::invalid_argument("invalid ip address for listening");
  }
  setup_socket();
}

Server::~Server() { close(listening_socket); }

void Server::setup_socket() {
  listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listening_socket < 0) {
    throw std::runtime_error("can't create socket");
  }

  int opt = 1;
  if (setsockopt(listening_socket, SOL_SOCKET, SO_REUSEADDR, &opt,
                 sizeof(opt)) < 0) {
    throw std::runtime_error("can't set socket opts");
  }

  bind_socket();
  start_listening();
}

void Server::bind_socket() {
  if (bind(listening_socket, reinterpret_cast<sockaddr *>(&server_address),
           sizeof(server_address)) < 0) {
    throw std::runtime_error("can't bind socket");
  }
  std::cout << "[inf] socket bounded" << std::endl;
}

void Server::start_listening() {
  if (listen(listening_socket, 5) < 0) {
    throw std::runtime_error("can't listen on socket");
  }
  std::cout << "[inf] serv is listening" << std::endl;
}

void Server::start() {
  while (true) {
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int client_socket =
        accept(listening_socket, reinterpret_cast<sockaddr *>(&client_addr),
               &client_len);
    if (client_socket < 0) {
      std::cout << "[err] can't accept connection" << std::endl;
      continue;
    }
    execute(client_socket, client_addr);
    close(client_socket);
  }
}

void Server::execute(int client_socket, const sockaddr_in &client_addr) const {
  while (true) {
    uint32_t net_msg_len = 0;
    ssize_t r =
        recv(client_socket, &net_msg_len, sizeof(net_msg_len), MSG_WAITALL);
    if (r <= 0 || r != sizeof(net_msg_len))
      break;

    uint32_t msg_len = ntohl(net_msg_len);
    if (msg_len == 0)
      continue;

    std::vector<char> buffer(msg_len);
    r = recv(client_socket, buffer.data(), msg_len, MSG_WAITALL);
    if (r <= 0 || static_cast<uint32_t>(r) != msg_len)
      break;

    std::vector<char> result = callback(buffer);

    bool forwarded = false;
    if (destination_ip && destination_port) {
      int dst_sock = socket(AF_INET, SOCK_STREAM, 0);
      if (dst_sock < 0)
        continue;

      sockaddr_in dst_addr{};
      dst_addr.sin_family = AF_INET;
      dst_addr.sin_port = htons(*destination_port);
      if (inet_pton(AF_INET, destination_ip->c_str(), &dst_addr.sin_addr) <=
          0) {
        close(dst_sock);
        continue;
      }

      if (connect(dst_sock, reinterpret_cast<sockaddr *>(&dst_addr),
                  sizeof(dst_addr)) < 0) {
        close(dst_sock);
        continue;
      }

      uint32_t len_net = htonl(static_cast<uint32_t>(result.size()));
      if (send(dst_sock, &len_net, sizeof(len_net), 0) < 0) {
        close(dst_sock);
        continue;
      }

      if (send(dst_sock, result.data(), result.size(), 0) < 0) {
        close(dst_sock);
        continue;
      }

      uint32_t net_answ_len = 0;
      r = recv(dst_sock, &net_answ_len, sizeof(net_answ_len), MSG_WAITALL);
      if (r != sizeof(net_answ_len)) {
        close(dst_sock);
        continue;
      }

      uint32_t answ_len = ntohl(net_answ_len);
      std::vector<char> answ_buf(answ_len);
      r = recv(dst_sock, answ_buf.data(), answ_len, MSG_WAITALL);
      if (r != static_cast<ssize_t>(answ_len)) {
        close(dst_sock);
        continue;
      }

      std::cout << "[inf] received answ : "
                << std::string(answ_buf.begin(), answ_buf.end()) << std::endl;

      close(dst_sock);
      forwarded = true;
    }

    std::string answ_msg = "data received";
    uint32_t answ_len = htonl(static_cast<uint32_t>(answ_msg.size()));

    if (send(client_socket, &answ_len, sizeof(answ_len), 0) !=
        sizeof(answ_len)) {
      break;
    }

    if (send(client_socket, answ_msg.data(), answ_msg.size(), 0) !=
        static_cast<ssize_t>(answ_msg.size())) {
      break;
    }
  }
}

ClientConnector::ClientConnector(const std::string &ip, int port)
    : destination_ip(ip), destination_port(port) {}

void ClientConnector::connect_to_server() {
  sockDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (sockDescriptor < 0) {
    throw std::runtime_error("err creating socket");
  }

  sockaddr_in server_addr{};
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(destination_port);

  if (inet_pton(AF_INET, destination_ip.c_str(), &server_addr.sin_addr) <= 0) {
    close(sockDescriptor);
    throw std::invalid_argument("invalid ip");
  }

  if (connect(sockDescriptor, reinterpret_cast<sockaddr *>(&server_addr),
              sizeof(server_addr)) < 0) {
    close(sockDescriptor);
    throw std::runtime_error("can't connect to server");
  }
}

void ClientConnector::send_message(const std::string &message) {
  if (sockDescriptor < 0) {
    throw std::runtime_error("socket not connected");
  }

  uint32_t msg_len = message.size();
  uint32_t net_len = htonl(msg_len);

  if (send(sockDescriptor, &net_len, sizeof(net_len), 0) != sizeof(net_len)) {
    throw std::runtime_error("err sending msg length");
  }

  if (msg_len > 0) {
    if (send(sockDescriptor, message.c_str(), msg_len, 0) !=
        static_cast<ssize_t>(msg_len)) {
      throw std::runtime_error("err sending msg data");
    }
  }

  uint32_t net_answ_len = 0;
  ssize_t r =
      recv(sockDescriptor, &net_answ_len, sizeof(net_answ_len), MSG_WAITALL);
  if (r != sizeof(net_answ_len)) {
    throw std::runtime_error("err receiving answ length");
  }

  uint32_t answ_len = ntohl(net_answ_len);
  std::vector<char> answ_buf(answ_len);
  r = recv(sockDescriptor, answ_buf.data(), answ_len, MSG_WAITALL);
  if (r != static_cast<ssize_t>(answ_len)) {
    throw std::runtime_error("err receiving answ msg");
  }

  std::string answ(answ_buf.begin(), answ_buf.end());
  std::cout << "answ : " << answ << std::endl;
}

ClientConnector::~ClientConnector() {
  if (sockDescriptor >= 0) {
    close(sockDescriptor);
  }
}
