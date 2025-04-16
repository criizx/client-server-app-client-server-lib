#include "handler.hpp"
#include <iostream>

std::string handler::display(std::string str) {
  std::cout << str << std::endl;
  return "";
}

std::vector<char> handler::format_data_wrapper(const std::vector<char> &input) {
  std::string str_input(input.begin(), input.end());
  std::string formatted = display(str_input);
  return std::vector<char>(formatted.begin(), formatted.end());
}