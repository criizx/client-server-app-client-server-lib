#include "handler.hpp"

#include <sstream>
#include <unordered_set>

std::string handler::format_data(const std::string &input) {
  std::istringstream iss(input);
  std::vector<std::string> words;
  std::string word;

  while (iss >> word) {
    words.push_back(word);
  }

  std::unordered_set<std::string> seen_words;
  std::vector<std::string> unique_words;

  for (const auto &w : words) {
    if (!seen_words.count(w)) {
      seen_words.insert(w);
      unique_words.push_back(w);
    }
  }

  std::string result;
  for (size_t i = 0; i < unique_words.size(); ++i) {
    if (i > 0)
      result += " ";
    result += unique_words[i];
  }

  return result;
}

std::vector<char> handler::format_data_wrapper(const std::vector<char> &input) {
  std::string str_input(input.begin(), input.end());
  std::string formatted = format_data(str_input);
  return std::vector<char>(formatted.begin(), formatted.end());
}
