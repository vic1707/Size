#pragma once

#pragma region FMT fmt::formatter
/* GTEST */
#include "gtest/gtest.h"
/* SIZE */
#include <size.hpp>
#include <size_fmt.hpp>
using namespace size::size_literals;

GTEST_TEST(FMT,  default_format) {
  EXPECT_EQ(fmt::format("{}", 1_B), "1 B") << "Should display 1_B as '1 B'";
  EXPECT_EQ(fmt::format("{}", 2_KB), "2 KB") << "Should display 2_KB as '2 KB'";
  EXPECT_EQ(fmt::format("{}", 2_KiB), "2 KiB") << "Should display 2_KiB as '2 KiB'";
  EXPECT_EQ(fmt::format("{}", 3_MB), "3 MB") << "Should display 3_MB as '3 MB'";
  EXPECT_EQ(fmt::format("{}", 3_MiB), "3 MiB") << "Should display 3_MiB as '3 MiB'";
  EXPECT_EQ(fmt::format("{}", 4_GB), "4 GB") << "Should display 4_GB as '4 GB'";
  EXPECT_EQ(fmt::format("{}", 4_GiB), "4 GiB") << "Should display 4_GiB as '4 GiB'";
  EXPECT_EQ(fmt::format("{}", 5_TB), "5 TB") << "Should display 5_TB as '5 TB'";
  EXPECT_EQ(fmt::format("{}", 5_TiB), "5 TiB") << "Should display 5_TiB as '5 TiB'";
  EXPECT_EQ(fmt::format("{}", 6_PB), "6 PB") << "Should display 6_PB as '6 PB'";
  EXPECT_EQ(fmt::format("{}", 6_PiB), "6 PiB") << "Should display 6_PiB as '6 PiB'";
  EXPECT_EQ(fmt::format("{}", 7_EB), "7 EB") << "Should display 7_EB as '7 EB'";
  EXPECT_EQ(fmt::format("{}", 7_EiB), "7 EiB") << "Should display 7_EiB as '7 EiB'";
  EXPECT_EQ(fmt::format("{}", 8_ZB), "8 ZB") << "Should display 8_ZB as '8 ZB'";
  EXPECT_EQ(fmt::format("{}", 8_ZiB), "8 ZiB") << "Should display 8_ZiB as '8 ZiB'";
  EXPECT_EQ(fmt::format("{}", 9_YB), "9 YB") << "Should display 9_YB as '9 YB'";
  EXPECT_EQ(fmt::format("{}", 9_YiB), "9 YiB") << "Should display 9_YiB as '9 YiB'";
  // should support casting to other base
  EXPECT_EQ(fmt::format("{}", (1_KB).to_base2()), "1000 B") << "Should display 1_KB as '1000 B'";
  EXPECT_EQ(fmt::format("{}", (1_KiB).to_base10()), "1.024 KB") << "Should display 1_KiB as '1.024 KB'";
}

GTEST_TEST(FMT, specify_base) {
  EXPECT_EQ(fmt::format("{:#b}", 1_KB), "1000 B") << "Should display 1_KB as '1000 B'";
  EXPECT_EQ(fmt::format("{:#b}", 2_KB), "1.953125 KiB") << "Should display 2_KB as '1.953125 KiB'";
  EXPECT_EQ(fmt::format("{:#d}", 1_KiB), "1.024 KB") << "Should display 1_KiB as '1.024 KB'";
  EXPECT_EQ(fmt::format("{:#d}", 2_KiB), "2.048 KB") << "Should display 2_KiB as '2.048 KB'";
}

GTEST_TEST(FMT, specify_unit) {
  EXPECT_EQ(fmt::format("{:#B}", 1_KB), "1000 B") << "Should display 1_KB as '1000 B'";
  EXPECT_EQ(fmt::format("{:#B}", 1_KiB), "1024 B") << "Should display 1_KiB as '1024 B'";
  EXPECT_EQ(fmt::format("{:#E}", 1_YB), "1000000 EB") << "Should display 1_YB as '1000000 EB'";
  EXPECT_EQ(fmt::format("{:#E}", 1_YiB), "1048576 EiB") << "Should display 1_YiB as '1048576 EiB'";
}

GTEST_TEST(FMT, specify_positions) {
  EXPECT_EQ(fmt::format("{:#%U}", 1_KB), "KB") << "Should display '{:#%U}' of 1_KB as 'KB'";
  EXPECT_EQ(fmt::format("{:#%V}", 1_KB), "1") << "Should display '{:#%V}' of 1_KB as '1'";
  EXPECT_EQ(fmt::format("{:#%U %V}", 1_KB), "KB 1") << "Should display '{:#%U %V}' of 1_KB as 'KB 1'";
  EXPECT_EQ(fmt::format("{:#%V %U}", 1_KB), "1 KB") << "Should display '{:#%V %U}' of 1_KB as '1 KB'";
  EXPECT_EQ(fmt::format("{:#%V %U %V}", 1_KB), "1 KB 1") << "Should display '{:#%V %U %V}' of 1_KB as '1 KB 1'";
  EXPECT_EQ(fmt::format("{:#%U %V %U}", 1_KB), "KB 1 KB") << "Should display '{:#%U %V %U}' of 1_KB as 'KB 1 KB'";
}

GTEST_TEST(FMT, specify_in_between_text) {
  EXPECT_EQ(fmt::format("{:#%U_%V}", 1_KB), "KB_1") << "Should display '{:#%U_%V}' of 1_KB as 'KB_1'";
  EXPECT_EQ(fmt::format("{:#%V_%U}", 1_KB), "1_KB") << "Should display '{:#%V_%U}' of 1_KB as '1_KB'";
  EXPECT_EQ(fmt::format("{:#%V_xx_%U}", 1_KB), "1_xx_KB") << "Should display '{:#%V_xx_%U}' of 1_KB as '1_xx_KB'";
  EXPECT_EQ(fmt::format("{:#%U_xx_%V}", 1_KB), "KB_xx_1") << "Should display '{:#%U_xx_%V}' of 1_KB as 'KB_xx_1'";
}

GTEST_TEST(FMT, change_unit_behavior) {
  // Default
  EXPECT_EQ(fmt::format("{:#%U}", 1_KB), "KB") << "Should display '{:#%U}' of 1_KB as 'KB'";
  /* Available specifier 'l' | 'L' | 'a' | 'A' */
  // LongLowercase
  EXPECT_EQ(fmt::format("{:#%l}", 1_KB), "kilobyte") << "Should display '{:#%l}' of 1_KB as 'kilobyte'";
  EXPECT_EQ(fmt::format("{:#%l}", 1_KiB), "kibibyte") << "Should display '{:#%l}' of 1_KiB as 'kibibyte'";
  // LongUppercase
  EXPECT_EQ(fmt::format("{:#%L}", 1_KB), "Kilobyte") << "Should display '{:#%L}' of 1_KB as 'Kilobyte'";
  EXPECT_EQ(fmt::format("{:#%L}", 1_KiB), "Kibibyte") << "Should display '{:#%L}' of 1_KiB as 'Kibibyte'";
  // AbbreviatedLowercase
  EXPECT_EQ(fmt::format("{:#%a}", 1_KB), "kb") << "Should display '{:#%a}' of 1_KB as 'kb'";
  EXPECT_EQ(fmt::format("{:#%a}", 1_KiB), "kib") << "Should display '{:#%a}' of 1_KiB as 'kib'";
  // AbbreviatedUppercase
  EXPECT_EQ(fmt::format("{:#%A}", 1_KB), "KB") << "Should display '{:#%A}' of 1_KB as 'KB'";
  EXPECT_EQ(fmt::format("{:#%A}", 1_KiB), "KiB") << "Should display '{:#%A}' of 1_KiB as 'KiB'";
}

GTEST_TEST(FMT, change_value_behavior) {
  // Default
  EXPECT_EQ(fmt::format("{:#%V}", 1_KB), "1") << "Should display '{:#%V}' of 1_KB as '1'";
  /* Available specifier 'e' | 'f' */
  // Exponent
  EXPECT_EQ(fmt::format("{:#%e}", 1000_B), "1.000000e+03") << "Should display '{:#%e}' of 1_KB as '1.000000e+03'";
  // Fixed
  EXPECT_EQ(fmt::format("{:#%f}", 1_KiB), "1.000000") << "Should display '{:#%f}' of 1_KiB as '1.000000'";
  EXPECT_EQ(fmt::format("{:#b%f}", 1_KB), "1000") << "Should display '{:#b%f}' of 1_KB as '1000'";
}

GTEST_TEST(FMT, precision) {
  EXPECT_EQ(fmt::format("{:.2#d%f}", 1_KiB), "1.02") << "Should display '{:.2#d%f}' of 1_KiB as '1.02'";
  EXPECT_EQ(fmt::format("{:.2#d%f}", 1_KB), "1.00") << "Should display '{:.2#d%f}' of 1_KB as '1.00'";
  // 1'047'104_B is 1022.5625 KiB
  EXPECT_EQ(fmt::format("{:.0#b%f}", 1'047'104_B), "1023") << "Should display '{:.0#b%f}' of 1'047'104_B as '1023'";
  EXPECT_EQ(fmt::format("{:.1#b%f}", 1'047'104_B), "1022.6") << "Should display '{:.1#b%f}' of 1'047'104_B as '1022.6'";
  EXPECT_EQ(fmt::format("{:.2#b%f}", 1'047'104_B), "1022.56") << "Should display '{:.2#b%f}' of 1'047'104_B as '1022.56'";
  EXPECT_EQ(fmt::format("{:.3#b%f}", 1'047'104_B), "1022.562") << "Should display '{:.3#b%f}' of 1'047'104_B as '1022.562'";
  EXPECT_EQ(fmt::format("{:.4#b%f}", 1'047'104_B), "1022.5625") << "Should display '{:.4#b%f}' of 1'047'104_B as '1022.5625'";
  // SIZE_KEEP_BYTES_DECIMALS is not defined
  // so Bytes should never have decimals in floating point notation
  EXPECT_EQ(fmt::format("{:.2#d%V}", 1_B), "1") << "Should display '{:.2#d%V}' of 1_B as '1'";
  EXPECT_EQ(fmt::format("{:.2#d%f}", 1_B), "1") << "Should display '{:.2#d%f}' of 1_B as '1'";
}
#pragma endregion
