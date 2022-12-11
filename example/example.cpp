#include <iostream>
#include <iomanip>
#include "size.hpp"
#include "size_fmt.hpp"

#include <fmt/format.h>

int main() {
  std::cout << fmt::format("'{:^30.2#B%f %U}'", size::Size{1050}) << std::endl;
  std::cout << fmt::format("'{}'", size::Size{1050}) << std::endl;
  std::cout << fmt::format("'{:}'", size::Size{1050}) << std::endl;
  std::cout << fmt::format("'{:.2}'", size::Size{1050}) << std::endl;
  std::cout << fmt::format("'{:.2#d}'", size::Size{1050}) << std::endl;
  return 0;
}
