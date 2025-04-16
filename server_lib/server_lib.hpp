#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <functional>
#include <optional>
#include <string>
#include <vector>

class Server {
private:
  int listening_socket;
  sockaddr_in server_address;

  std::optional<std::string> destination_ip;
  std::optional<int> destination_port;

  std::function<std::vector<char>(const std::vector<char> &)> callback;

  void setup_socket();
  void bind_socket();
  void start_listening();

public:
  Server(const std::string &ip, int port,
         const std::function<std::vector<char>(const std::vector<char> &)> &cb);

  Server(const std::string &listen_ip, int listen_port,
         const std::string &dest_ip, int dest_port,
         const std::function<std::vector<char>(const std::vector<char> &)> &cb);

  ~Server();

  void start();
  void execute(int client_socket, const sockaddr_in &client_addr) const;
};

class ClientConnector {
private:
  std::string destination_ip;
  int destination_port;
  int sockDescriptor = -1;

public:
  ClientConnector(const std::string &ip, int port);
  void connect_to_server();
  void send_message(const std::string &message);
  ~ClientConnector();
};
