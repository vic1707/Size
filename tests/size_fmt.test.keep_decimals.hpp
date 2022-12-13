#pragma region SIZE_KEEP_BYTES_DECIMALS is defined
/* GTEST */
#include "gtest/gtest.h"
/* SIZE */
#include "size.hpp"
#define SIZE_KEEP_BYTES_DECIMALS
#include "size_fmt.hpp"
using namespace size::size_literals;

GTEST_TEST(FMT, precision_SIZE_KEEP_BYTES_DECIMALS_defined) {
  EXPECT_EQ(fmt::format("{:.2}", 1_B), "1.00 B") << "Should display '{:.2}' of 1_B as '1.00 B'";
  EXPECT_EQ(fmt::format("{:.2#d%f}", 1_B), "1.00") << "Should display '{:.2#d%f}' of 1_B as '1.00'";
  // setting `%V` doesn't trigger decimal display for bytes
  EXPECT_EQ(fmt::format("{:.2#d%V}", 1_B), "1") << "Should display '{:.2#d%V}' of 1_B as '1'";
}

#undef SIZE_KEEP_BYTES_DECIMALS
#pragma endregion
