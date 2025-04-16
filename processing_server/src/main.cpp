#include <cstdlib>
#include <iostream>
#include <string>

#include "../../server_lib/server_lib.hpp"
#include "../../server_lib/validator.hpp"
#include "handler.hpp"

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0]
              << " <listen_ip> <listen_port> <dest_ip> <dest_port>"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string listen_ip(argv[1]);
  std::string listen_port(argv[2]);
  std::string dest_ip(argv[3]);
  std::string dest_port(argv[4]);

  try {
    Validator::validate_IP(listen_ip);
    Validator::validate_port(listen_port);
    Validator::validate_IP(dest_ip);
    Validator::validate_port(dest_port);
  } catch (const std::exception &e) {
    std::cerr << "val err: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  try {
    Server server(listen_ip, std::stoi(listen_port), dest_ip,
                  std::stoi(dest_port), handler::format_data_wrapper);
    server.start();
  } catch (const std::exception &e) {
    std::cerr << "err: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
