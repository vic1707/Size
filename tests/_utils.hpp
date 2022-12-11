#pragma once
/* STD */
#include <iostream>
#include <sstream>

template<typename T>
concept HasOStreamOutOverload = requires(const T& item) { 
  std::cout << item;
};

template<HasOStreamOutOverload T>
std::string get_stream_output(const T& item) {
  static std::stringstream ss;
  ss << item;
  std::string out = ss.str();
  ss.str("");
  return out;
}
