#include "validator.hpp"

#include <arpa/inet.h>

#include <cctype>
#include <stdexcept>

void Validator::validate_port(const std::string &port) {
  if (port.empty() || port.size() > 5) {
    throw std::invalid_argument("invalid port");
  }
  for (char c : port) {
    if (!std::isdigit(c)) {
      throw std::invalid_argument("invalid port");
    }
  }
  int portNum = std::stoi(port);
  if (portNum < 0 || portNum > 65535) {
    throw std::out_of_range("invalid port");
  }
}

void Validator::validate_IP(const std::string &ip) {
  sockaddr_in sa;
  if (inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr)) != 1) {
    throw std::invalid_argument("invalid IP");
  }
}
