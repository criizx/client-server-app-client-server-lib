#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <string>

class Validator {
public:
  static void validate_port(const std::string &port);
  static void validate_IP(const std::string &ip);
};

#endif
