#include "gtest/gtest.h"
/* TESTS */
#include "size.test.hpp"
#include "size_fmt.test.hpp"
// need to find a way to keep both tests
// #include "size_fmt.test.keep_decimals.hpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
