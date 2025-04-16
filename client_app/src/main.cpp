#include <iostream>
#include <string>

#include "../../server_lib/server_lib.hpp"
#include "../../server_lib/validator.hpp"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: <send_ip> <send_port>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string send_ip(argv[1]);
  std::string send_port(argv[2]);

  try {
    Validator::validate_port(send_port);
    Validator::validate_IP(send_ip);

    ClientConnector client(send_ip, std::stoi(send_port));
    client.connect_to_server();
    std::cout << "connected\n";

    std::string line;
    while (std::getline(std::cin, line)) {
      try {
        client.send_message(line);
      } catch (const std::exception &e) {
        std::cerr << "sending err: " << e.what() << std::endl;
      }
    }

    return EXIT_SUCCESS;

  } catch (const std::exception &e) {
    std::cerr << "err: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
}
