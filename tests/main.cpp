#include "gtest/gtest.h"
/* TESTS */
#include "size.test.hpp"
#include "size_fmt.test.hpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
