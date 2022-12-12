#pragma once

/* UTILITIES */
#include "_suffix128.hpp"
#include "_utils.hpp"
/* GTEST */
#include "gtest/gtest.h"
/* SIZE */
#include "size.hpp"
using namespace size::size_literals;

/* Tests */
#pragma region Size constructors
GTEST_TEST(constructors, default_constructor) {
  size::Size s;
  EXPECT_EQ(s.bytes(), 0) << "Default constructor should initialize to 0 bytes";
};

GTEST_TEST(constructors, bytes_constructor) {
  size::Size s(1);
  EXPECT_EQ(s.bytes(), 1) << "Size constructor should initialize to number of bytes given";
};

GTEST_TEST(constructors, unit_constructor) {
  size::Size s(1, size::Unit::KILOBYTE);
  EXPECT_EQ(s.bytes(), 1000) << "Size constructor should initialize to a number given in a unit";
};

GTEST_TEST(constructors, static_bytes_constructor) {
  auto B = size::from_bytes(1);
  EXPECT_EQ(B.bytes(), 1) << "Size constructors from_bytes should initialize to a number of bytes";
};

GTEST_TEST(constructors, static_kibibytes_constructor) {
  auto KiB = size::from_kibibytes(1);
  EXPECT_EQ(KiB.bytes(), 1024) << "Size constructors from_kibibytes should initialize to a number of kibibytes";
};

GTEST_TEST(constructors, static_kilobytes_constructor) {
  auto KB = size::from_kilobytes(1);
  EXPECT_EQ(KB.bytes(), 1000) << "Size constructors from_kilobytes should initialize to a number of kilobytes";
};

GTEST_TEST(constructors, static_mebibytes_constructor) {
  auto MiB = size::from_mebibytes(1);
  EXPECT_EQ(MiB.bytes(), 1048576) << "Size constructors from_mebibytes should initialize to a number of mebibytes";
};

GTEST_TEST(constructors, static_megabytes_constructor) {
  auto MB = size::from_megabytes(1);
  EXPECT_EQ(MB.bytes(), 1000000) << "Size constructors from_megabytes should initialize to a number of megabytes";
};

GTEST_TEST(constructors, static_gibibytes_constructor) {
  auto GiB = size::from_gibibytes(1);
  EXPECT_EQ(GiB.bytes(), 1073741824) << "Size constructors from_gibibytes should initialize to a number of gibibytes";
};

GTEST_TEST(constructors, static_gigabytes_constructor) {
  auto GB = size::from_gigabytes(1);
  EXPECT_EQ(GB.bytes(), 1000000000) << "Size constructors from_gigabytes should initialize to a number of gigabytes";
};

GTEST_TEST(constructors, static_tebibytes_constructor) {
  auto TiB = size::from_tebibytes(1);
  EXPECT_EQ(TiB.bytes(), 1099511627776) << "Size constructors from_tebibytes should initialize to a number of tebibytes";
};

GTEST_TEST(constructors, static_terabytes_constructor) {
  auto TB = size::from_terabytes(1);
  EXPECT_EQ(TB.bytes(), 1000000000000) << "Size constructors from_terabytes should initialize to a number of terabytes";
};

GTEST_TEST(constructors, static_pebibytes_constructor) {
  auto PiB = size::from_pebibytes(1);
  EXPECT_EQ(PiB.bytes(), 1125899906842624) << "Size constructors from_pebibytes should initialize to a number of pebibytes";
};

GTEST_TEST(constructors, static_petabytes_constructor) {
  auto PB = size::from_petabytes(1);
  EXPECT_EQ(PB.bytes(), 1000000000000000) << "Size constructors from_petabytes should initialize to a number of petabytes";
};

GTEST_TEST(constructors, static_exbibytes_constructor) {
  auto EiB = size::from_exbibytes(1);
  EXPECT_EQ(EiB.bytes(), 1152921504606846976) << "Size constructors from_exbibytes should initialize to a number of exbibytes";
};

GTEST_TEST(constructors, static_exabytes_constructor) {
  auto EB = size::from_exabytes(1);
  EXPECT_EQ(EB.bytes(), 1000000000000000000) << "Size constructors from_exabytes should initialize to a number of exabytes";
};

GTEST_TEST(constructors, static_zebibytes_constructor) {
  auto ZiB = size::from_zebibytes(1);
  EXPECT_EQ(ZiB.bytes(), 1180591620717411303424_128) << "Size constructors from_zebibytes should initialize to a number of zebibytes";
};

GTEST_TEST(constructors, static_zettabytes_constructor) {
  auto ZB = size::from_zettabytes(1);
  EXPECT_EQ(ZB.bytes(), 1000000000000000000000_128) << "Size constructors from_zettabytes should initialize to a number of zettabytes";
};

GTEST_TEST(constructors, static_yobibytes_constructor) {
  auto YiB = size::from_yobibytes(1);
  EXPECT_EQ(YiB.bytes(), 1208925819614629174706176_128) << "Size constructors from_yobibytes should initialize to a number of yobibytes";
};

GTEST_TEST(constructors, static_yottabytes_constructor) {
  auto YB = size::from_yottabytes(1);
  EXPECT_EQ(YB.bytes(), 1000000000000000000000000_128) << "Size constructors from_yottabytes should initialize to a number of yottabytes";
};

GTEST_TEST(constructors, static_robibyte_constructor) {
  auto RiB = size::from_robibytes(1);
  EXPECT_EQ(RiB.bytes(), 1237940039285380274899124224_128) << "Size constructors from_robibytes should initialize to a number of robibytes";
};

GTEST_TEST(constructors, static_ronnabyte_constructor) {
  auto RN = size::from_ronnabytes(1);
  EXPECT_EQ(RN.bytes(), 1000000000000000000000000000_128) << "Size constructors from_ronnabytes should initialize to a number of ronnabytes";
};

GTEST_TEST(constructors, static_quebibyte_constructor) {
  auto QiB = size::from_quebibytes(1);
  EXPECT_EQ(QiB.bytes(), 1267650600228229401496703205376_128) << "Size constructors from_quebibytes should initialize to a number of quebibytes";
};

GTEST_TEST(constructors, static_quettabyte_constructor) {
  auto QT = size::from_quettabytes(1);
  EXPECT_EQ(QT.bytes(), 1000000000000000000000000000000_128) << "Size constructors from_quettabytes should initialize to a number of quettabytes";
};

GTEST_TEST(constructors, copy_constructor) {
  size::Size s(1, size::Unit::KILOBYTE);
  size::Size s2(s);
  EXPECT_EQ(s2.bytes(), 1000) << "Size copy constructor should work";
};

GTEST_TEST(constructors, move_constructor) {
  size::Size s(1, size::Unit::KILOBYTE);
  size::Size s2(std::move(s));
  EXPECT_EQ(s2.bytes(), 1000) << "Size move constructor should work";
};

#pragma endregion

#pragma region Size size_literals
GTEST_TEST(size_literals, bytes) {
  EXPECT_EQ(1_B, 1) << "Size literal _B should work";
};

GTEST_TEST(size_literals, kibibytes) {
  EXPECT_EQ(1_KiB, 1024) << "Size literal _KiB should work";
};

GTEST_TEST(size_literals, kilobytes) {
  EXPECT_EQ(1_KB, 1000) << "Size literal _KB should work";
};

GTEST_TEST(size_literals, mebibytes) {
  EXPECT_EQ(1_MiB, 1048576) << "Size literal _MiB should work";
};

GTEST_TEST(size_literals, megabytes) {
  EXPECT_EQ(1_MB, 1000000) << "Size literal _MB should work";
};

GTEST_TEST(size_literals, gibibytes) {
  EXPECT_EQ(1_GiB, 1073741824) << "Size literal _GiB should work";
};

GTEST_TEST(size_literals, gigabytes) {
  EXPECT_EQ(1_GB, 1000000000) << "Size literal _GB should work";
};

GTEST_TEST(size_literals, tebibytes) {
  EXPECT_EQ(1_TiB, 1099511627776) << "Size literal _TiB should work";
};

GTEST_TEST(size_literals, terabytes) {
  EXPECT_EQ(1_TB, 1000000000000) << "Size literal _TB should work";
};

GTEST_TEST(size_literals, pebibytes) {
  EXPECT_EQ(1_PiB, 1125899906842624) << "Size literal _PiB should work";
};

GTEST_TEST(size_literals, petabytes) {
  EXPECT_EQ(1_PB, 1000000000000000) << "Size literal _PB should work";
};

GTEST_TEST(size_literals, exbibytes) {
  EXPECT_EQ(1_EiB, 1152921504606846976) << "Size literal _EiB should work";
};

GTEST_TEST(size_literals, exabytes) {
  EXPECT_EQ(1_EB, 1000000000000000000) << "Size literal _EB should work";
};

GTEST_TEST(size_literals, zebibytes) {
  EXPECT_EQ(1_ZiB, 1180591620717411303424_128) << "Size literal _ZiB should work";
};

GTEST_TEST(size_literals, zettabytes) {
  EXPECT_EQ(1_ZB, 1000000000000000000000_128) << "Size literal _ZB should work";
};

GTEST_TEST(size_literals, yobibytes) {
  EXPECT_EQ(1_YiB, 1208925819614629174706176_128) << "Size literal _YiB should work";
};

GTEST_TEST(size_literals, yottabytes) {
  EXPECT_EQ(1_YB, 1000000000000000000000000_128) << "Size literal _YB should work";
};

GTEST_TEST(size_literals, robibytes) {
  EXPECT_EQ(1_RiB, 1237940039285380274899124224_128) << "Size literal _RiB should work";
};

GTEST_TEST(size_literals, ronabytes) {
  EXPECT_EQ(1_RB, 1000000000000000000000000000_128) << "Size literal _RB should work";
};

GTEST_TEST(size_literals, quibibytes) {
  EXPECT_EQ(1_QiB, 1267650600228229401496703205376_128) << "Size literal _QiB should work";
};

GTEST_TEST(size_literals, quattabytes) {
  EXPECT_EQ(1_QB, 1000000000000000000000000000000_128) << "Size literal _QB should work";
};

#pragma endregion

#pragma region Size conversion
GTEST_TEST(conversion, bytes) {
  auto s = 1_KB;
  EXPECT_EQ(s.bytes(), 1000) << "Size conversion to bytes should work";
};

GTEST_TEST(conversion, kilobytes) {
  auto s = 1_MB;
  EXPECT_EQ(s.kilobytes(), 1000) << "Size conversion to kilobytes should work";
};

GTEST_TEST(conversion, kibibytes) {
  auto s = 1_MiB;
  EXPECT_EQ(s.kibibytes(), 1024) << "Size conversion to kibibytes should work";
};

GTEST_TEST(conversion, megabytes) {
  auto s = 1_GB;
  EXPECT_EQ(s.megabytes(), 1000) << "Size conversion to megabytes should work";
};

GTEST_TEST(conversion, mebibytes) {
  auto s = 1_GiB;
  EXPECT_EQ(s.mebibytes(), 1024) << "Size conversion to mebibytes should work";
};

GTEST_TEST(conversion, gigabytes) {
  auto s = 1_TB;
  EXPECT_EQ(s.gigabytes(), 1000) << "Size conversion to gigabytes should work";
};

GTEST_TEST(conversion, gibibytes) {
  auto s = 1_TiB;
  EXPECT_EQ(s.gibibytes(), 1024) << "Size conversion to gibibytes should work";
};

GTEST_TEST(conversion, terabytes) {
  auto s = 1_PB;
  EXPECT_EQ(s.terabytes(), 1000) << "Size conversion to terabytes should work";
};

GTEST_TEST(conversion, tebibytes) {
  auto s = 1_PiB;
  EXPECT_EQ(s.tebibytes(), 1024) << "Size conversion to tebibytes should work";
};

GTEST_TEST(conversion, petabytes) {
  auto s = 1_EB;
  EXPECT_EQ(s.petabytes(), 1000) << "Size conversion to petabytes should work";
};

GTEST_TEST(conversion, pebibytes) {
  auto s = 1_EiB;
  EXPECT_EQ(s.pebibytes(), 1024) << "Size conversion to pebibytes should work";
};

GTEST_TEST(conversion, exabytes) {
  auto s = 1_ZB;
  EXPECT_EQ(s.exabytes(), 1000) << "Size conversion to exabytes should work";
};

GTEST_TEST(conversion, exbibytes) {
  auto s = 1_ZiB;
  EXPECT_EQ(s.exbibytes(), 1024) << "Size conversion to exbibytes should work";
};

GTEST_TEST(conversion, zettabytes) {
  auto s = 1_YB;
  EXPECT_EQ(s.zettabytes(), 1000) << "Size conversion to zettabytes should work";
};

GTEST_TEST(conversion, zebibytes) {
  auto s = 1_YiB;
  EXPECT_EQ(s.zebibytes(), 1024) << "Size conversion to zebibytes should work";
};

GTEST_TEST(conversion, yottabytes) {
  auto s = 1_RB;
  EXPECT_EQ(s.yottabytes(), 1000) << "Size conversion to yottabytes should work";
};

GTEST_TEST(conversion, yobibytes) {
  auto s = 1_RiB;
  EXPECT_EQ(s.yobibytes(), 1024) << "Size conversion to yobibytes should work";
};

GTEST_TEST(conversion, ronnabytes) {
  auto s = 1_QB;
  EXPECT_EQ(s.ronnabytes(), 1000) << "Size conversion to ronnabytes should work";
};

GTEST_TEST(conversion, robibytes) {
  auto s = 1_QiB;
  EXPECT_EQ(s.robibytes(), 1024) << "Size conversion to robibytes should work";
};

GTEST_TEST(conversion, quettabytes) {
  auto s = 500_RB;
  EXPECT_EQ(s.quettabytes(), .5) << "Size conversion to quettabytes should work";
};

GTEST_TEST(conversion, quebibytes) {
  auto s = 512_RiB;
  EXPECT_EQ(s.quebibytes(), .5) << "Size conversion to quebibytes should work";
};

#pragma endregion

#pragma region Size operators logical
GTEST_TEST(operators_logical, equality) {
  ASSERT_TRUE(1_KiB == 1024_B) << "1_KiB == 1024_B should be true";
  ASSERT_FALSE(1_KB == 1_B) << "1_KB == 1_B should be false";
  ASSERT_FALSE(1_KB == 1_KiB) << "1_KB == 1_KiB should be false";
};

GTEST_TEST(operators_logical, inequality) {
  ASSERT_TRUE(1_KB != 1_B) << "1_KB != 1_B should be true";
  ASSERT_TRUE(1_KB != 1_KiB) << "1_KB != 1_KiB should be true";
  ASSERT_FALSE(1_KiB != 1024_B) << "1_KiB != 1024_B should be false";
};

GTEST_TEST(operators_logical, less_than) {
  ASSERT_TRUE(1_B < 1_KB) << "1_B < 1_KB should be true";
  ASSERT_TRUE(1_KB < 1_KiB) << "1_KB < 1_KiB should be true";
  ASSERT_FALSE(1_KB < 1_B) << "1_KB < 1_B should be false";
  ASSERT_FALSE(1_KiB < 1_KB) << "1_KiB < 1_KB should be false";
  ASSERT_FALSE(1_KiB < 1_KiB) << "1_KiB < 1_KiB should be false";
};

GTEST_TEST(operators_logical, greater_than) {
  ASSERT_TRUE(1_KB > 1_B) << "1_KB > 1_B should be true";
  ASSERT_TRUE(1_KiB > 1_KB) << "1_KiB > 1_KB should be true";
  ASSERT_FALSE(1_B > 1_KB) << "1_B > 1_KB should be false";
  ASSERT_FALSE(1_KB > 1_KiB) << "1_KB > 1_KiB should be false";
  ASSERT_FALSE(1_KiB > 1_KiB) << "1_KiB > 1_KiB should be false";
};

GTEST_TEST(operators_logical, less_than_or_equal) {
  ASSERT_TRUE(1_B <= 1_KB) << "1_B <= 1_KB should be true";
  ASSERT_TRUE(1_KB <= 1_KB) << "1_KB <= 1_KB should be true";
  ASSERT_FALSE(1_KB <= 1_B) << "1_KB <= 1_B should be false";
};

GTEST_TEST(operators_logical, greater_than_or_equal) {
  ASSERT_TRUE(1_KB >= 1_B) << "1_KB >= 1_B should be true";
  ASSERT_TRUE(1_KB >= 1_KB) << "1_KB >= 1_KB should be true";
  ASSERT_FALSE(1_B >= 1_KB) << "1_B >= 1_KB should be false";
};

#pragma endregion

#pragma region Size operators arithmetic
GTEST_TEST(operators_arithmetic, addition) {
  auto s = 1_KB + 1_KB;
  EXPECT_EQ(s.bytes(), 2000) << "Should be able to add two sizes";
};

GTEST_TEST(operators_arithmetic, subtraction) {
  auto s = 1_KB - 1_KB;
  EXPECT_EQ(s.bytes(), 0) << "Should be able to subtract two sizes";
};

GTEST_TEST(operators_arithmetic, multiplication) {
  auto s = 1_KB * 2;
  EXPECT_EQ(s.bytes(), 2000) << "Should be able to multiply a size by a scalar";
};

GTEST_TEST(operators_arithmetic, division) {
  auto s = 1_KB / 2;
  EXPECT_EQ(s.bytes(), 500) << "Should be able to divide a size by a scalar";
};

GTEST_TEST(operators_arithmetic, modulo) {
  auto s = 1_KB % 2;
  EXPECT_EQ(s.bytes(), 0) << "Should be able to modulo a size by a scalar";
};

GTEST_TEST(operators_arithmetic, postfix_increment) {
  auto s = 1_KB;
  auto x = s++;
  EXPECT_EQ(x.bytes(), 1000) << "Should be able to postfix increment a size";
  EXPECT_EQ(s.bytes(), 1001) << "Should be able to postfix increment a size";
};

GTEST_TEST(operators_arithmetic, prefix_increment) {
  auto s = 1_KB;
  auto x = ++s;
  EXPECT_EQ(x.bytes(), 1001) << "Should be able to prefix increment a size";
  EXPECT_EQ(s.bytes(), 1001) << "Should be able to prefix increment a size";
};

GTEST_TEST(operators_arithmetic, postfix_decrement) {
  auto s = 1_KB;
  auto x = s--;
  EXPECT_EQ(x.bytes(), 1000) << "Should be able to postfix decrement a size";
  EXPECT_EQ(s.bytes(), 999) << "Should be able to postfix decrement a size";
};

GTEST_TEST(operators_arithmetic, prefix_decrement) {
  auto s = 1_KB;
  auto x = --s;
  EXPECT_EQ(x.bytes(), 999) << "Should be able to prefix decrement a size";
  EXPECT_EQ(s.bytes(), 999) << "Should be able to prefix decrement a size";
};

GTEST_TEST(operators_arithmetic, bitshift_left) {
  auto s = 1_KB << 1;
  EXPECT_EQ(s.bytes(), 2000) << "Should be able to bitshift left a size";
};

GTEST_TEST(operators_arithmetic, bitshift_right) {
  auto s = 1_KB >> 1;
  EXPECT_EQ(s.bytes(), 500) << "Should be able to bitshift right a size";
};

#pragma endregion

#pragma region Size operators compound assignment
GTEST_TEST(operators_compound_assignment, compound_addition) {
  auto s = 1_KB;
  s += 1_KB;
  EXPECT_EQ(s.bytes(), 2000) << "Should be able to compound add a size";
};

GTEST_TEST(operators_compound_assignment, compound_subtraction) {
  auto s = 1_KB;
  s -= 1_KB;
  EXPECT_EQ(s.bytes(), 0) << "Should be able to compound subtract a size";
};

GTEST_TEST(operators_compound_assignment, compound_multiplication) {
  auto s = 1_KB;
  s *= 2;
  EXPECT_EQ(s.bytes(), 2000) << "Should be able to compound multiply a size";
};

GTEST_TEST(operators_compound_assignment, compound_division) {
  auto s = 1_KB;
  s /= 2;
  EXPECT_EQ(s.bytes(), 500) << "Should be able to compound divide a size";
};

GTEST_TEST(operators_compound_assignment, compound_modulo) {
  auto s = 1_KB;
  s %= 2;
  EXPECT_EQ(s.bytes(), 0) << "Should be able to compound modulo a size";
};

#pragma endregion

#pragma region Size operators ostream out
GTEST_TEST(operators_ostream_out, ostream_base2) {
  EXPECT_EQ(get_stream_output(1_B), "1 B") << "[Base2] - Should display 1_B as '1 B'";
  EXPECT_EQ(get_stream_output(2_KiB), "2 KiB") << "[Base2] - Should display 2_KiB as '2 KiB'";
  EXPECT_EQ(get_stream_output(3_MiB), "3 MiB") << "[Base2] - Should display 3_MiB as '3 MiB'";
  EXPECT_EQ(get_stream_output(4_GiB), "4 GiB") << "[Base2] - Should display 4_GiB as '4 GiB'";
  EXPECT_EQ(get_stream_output(5_TiB), "5 TiB") << "[Base2] - Should display 5_TiB as '5 TiB'";
  EXPECT_EQ(get_stream_output(6_PiB), "6 PiB") << "[Base2] - Should display 6_PiB as '6 PiB'";
  EXPECT_EQ(get_stream_output(7_EiB), "7 EiB") << "[Base2] - Should display 7_EiB as '7 EiB'";
  EXPECT_EQ(get_stream_output(8_ZiB), "8 ZiB") << "[Base2] - Should display 8_ZiB as '8 ZiB'";
  EXPECT_EQ(get_stream_output(9_YiB), "9 YiB") << "[Base2] - Should display 9_YiB as '9 YiB'";
  EXPECT_EQ(get_stream_output(10_RiB), "10 RiB") << "[Base2] - Should display 10_RiB as '10 RiB'";
  EXPECT_EQ(get_stream_output(11_QiB), "11 QiB") << "[Base2] - Should display 11_QiB as '11 QiB'";
  EXPECT_EQ(get_stream_output((1_GB).to_base2()), "953.674 MiB") << "[Base2] - Should display 1_GB as '953.674 MiB'";
  EXPECT_EQ(get_stream_output((2_GB).to_base2()), "1.86265 GiB") << "[Base2] - Should display 2_GB as '1.86265 GiB'";
  EXPECT_EQ(get_stream_output(512000_B), "500 KiB") << "[Base2] - Should display 512000_B as '500 KiB'";
};

GTEST_TEST(operators_ostream_out, ostream_base10) {
  EXPECT_EQ(get_stream_output(1_B), "1 B") << "[Base10] - Should display 1_B as '1 B'";
  EXPECT_EQ(get_stream_output(2_KB), "2 KB") << "[Base10] - Should display 2_KB as '2 KB'";
  EXPECT_EQ(get_stream_output(3_MB), "3 MB") << "[Base10] - Should display 3_MB as '3 MB'";
  EXPECT_EQ(get_stream_output(4_GB), "4 GB") << "[Base10] - Should display 4_GB as '4 GB'";
  EXPECT_EQ(get_stream_output(5_TB), "5 TB") << "[Base10] - Should display 5_TB as '5 TB'";
  EXPECT_EQ(get_stream_output(6_PB), "6 PB") << "[Base10] - Should display 6_PB as '6 PB'";
  EXPECT_EQ(get_stream_output(7_EB), "7 EB") << "[Base10] - Should display 7_EB as '7 EB'";
  EXPECT_EQ(get_stream_output(8_ZB), "8 ZB") << "[Base10] - Should display 8_ZB as '8 ZB'";
  EXPECT_EQ(get_stream_output(9_YB), "9 YB") << "[Base10] - Should display 9_YB as '9 YB'";
  EXPECT_EQ(get_stream_output(10_RB), "10 RB") << "[Base10] - Should display 10_RB as '10 RB'";
  EXPECT_EQ(get_stream_output(11_QB), "11 QB") << "[Base10] - Should display 11_QB as '11 QB'";
  EXPECT_EQ(get_stream_output((1_GiB).to_base10()), "1.07374 GB") << "[Base10] - Should display 1_GiB as '1.07374 GB'";
  EXPECT_EQ(get_stream_output((1000_GiB).to_base10()), "1.07374 TB") << "[Base10] - Should display 1000_GiB as '1.07374 TB'";
  EXPECT_EQ(get_stream_output((1000_B).to_base10()), "1 KB") << "[Base10] - Should display 1000_B as '1 KB'";
};

#pragma endregion

#pragma region Size styles
GTEST_TEST(styles, abbreviated) {
  size::CURRENT_STYLE = size::Style::Abbreviated;
  EXPECT_EQ(get_stream_output(1_B), "1 B") << "[Abbreviated] - Should display 1_B as '1 B'";
  EXPECT_EQ(get_stream_output(2_KB), "2 KB") << "[Abbreviated] - Should display 2_KB as '2 KB'";
  EXPECT_EQ(get_stream_output(3_MB), "3 MB") << "[Abbreviated] - Should display 3_MB as '3 MB'";
  EXPECT_EQ(get_stream_output(4_GB), "4 GB") << "[Abbreviated] - Should display 4_GB as '4 GB'";
  EXPECT_EQ(get_stream_output(5_TB), "5 TB") << "[Abbreviated] - Should display 5_TB as '5 TB'";
  EXPECT_EQ(get_stream_output(6_PB), "6 PB") << "[Abbreviated] - Should display 6_PB as '6 PB'";
  EXPECT_EQ(get_stream_output(7_EB), "7 EB") << "[Abbreviated] - Should display 7_EB as '7 EB'";
  EXPECT_EQ(get_stream_output(8_ZB), "8 ZB") << "[Abbreviated] - Should display 8_ZB as '8 ZB'";
  EXPECT_EQ(get_stream_output(9_YB), "9 YB") << "[Abbreviated] - Should display 9_YB as '9 YB'";
  EXPECT_EQ(get_stream_output(10_RB), "10 RB") << "[Abbreviated] - Should display 10_RB as '10 RB'";
  EXPECT_EQ(get_stream_output(11_QB), "11 QB") << "[Abbreviated] - Should display 11_QB as '11 QB'";
  EXPECT_EQ(get_stream_output(2_KiB), "2 KiB") << "[Abbreviated] - Should display 2_KiB as '2 KiB'";
  EXPECT_EQ(get_stream_output(3_MiB), "3 MiB") << "[Abbreviated] - Should display 3_MiB as '3 MiB'";
  EXPECT_EQ(get_stream_output(4_GiB), "4 GiB") << "[Abbreviated] - Should display 4_GiB as '4 GiB'";
  EXPECT_EQ(get_stream_output(5_TiB), "5 TiB") << "[Abbreviated] - Should display 5_TiB as '5 TiB'";
  EXPECT_EQ(get_stream_output(6_PiB), "6 PiB") << "[Abbreviated] - Should display 6_PiB as '6 PiB'";
  EXPECT_EQ(get_stream_output(7_EiB), "7 EiB") << "[Abbreviated] - Should display 7_EiB as '7 EiB'";
  EXPECT_EQ(get_stream_output(8_ZiB), "8 ZiB") << "[Abbreviated] - Should display 8_ZiB as '8 ZiB'";
  EXPECT_EQ(get_stream_output(9_YiB), "9 YiB") << "[Abbreviated] - Should display 9_YiB as '9 YiB'";
  EXPECT_EQ(get_stream_output(10_RiB), "10 RiB") << "[Abbreviated] - Should display 10_RiB as '10 RiB'";
  EXPECT_EQ(get_stream_output(11_QiB), "11 QiB") << "[Abbreviated] - Should display 11_QiB as '11 QiB'";
}

GTEST_TEST(styles, abbreviated_lowercase) {
  size::CURRENT_STYLE = size::Style::AbbreviatedLowercase;
  EXPECT_EQ(get_stream_output(1_B), "1 b") << "[AbbreviatedLowercase] - Should display 1_B as '1 b'";
  EXPECT_EQ(get_stream_output(2_KB), "2 kb") << "[AbbreviatedLowercase] - Should display 2_KB as '2 kb'";
  EXPECT_EQ(get_stream_output(3_MB), "3 mb") << "[AbbreviatedLowercase] - Should display 3_MB as '3 mb'";
  EXPECT_EQ(get_stream_output(4_GB), "4 gb") << "[AbbreviatedLowercase] - Should display 4_GB as '4 gb'";
  EXPECT_EQ(get_stream_output(5_TB), "5 tb") << "[AbbreviatedLowercase] - Should display 5_TB as '5 tb'";
  EXPECT_EQ(get_stream_output(6_PB), "6 pb") << "[AbbreviatedLowercase] - Should display 6_PB as '6 pb'";
  EXPECT_EQ(get_stream_output(7_EB), "7 eb") << "[AbbreviatedLowercase] - Should display 7_EB as '7 eb'";
  EXPECT_EQ(get_stream_output(8_ZB), "8 zb") << "[AbbreviatedLowercase] - Should display 8_ZB as '8 zb'";
  EXPECT_EQ(get_stream_output(9_YB), "9 yb") << "[AbbreviatedLowercase] - Should display 9_YB as '9 yb'";
  EXPECT_EQ(get_stream_output(10_RB), "10 rb") << "[AbbreviatedLowercase] - Should display 10_RB as '10 rb'";
  EXPECT_EQ(get_stream_output(11_QB), "11 qb") << "[AbbreviatedLowercase] - Should display 11_QB as '11 qb'";
  EXPECT_EQ(get_stream_output(2_KiB), "2 kib") << "[AbbreviatedLowercase] - Should display 2_KiB as '2 kib'";
  EXPECT_EQ(get_stream_output(3_MiB), "3 mib") << "[AbbreviatedLowercase] - Should display 3_MiB as '3 mib'";
  EXPECT_EQ(get_stream_output(4_GiB), "4 gib") << "[AbbreviatedLowercase] - Should display 4_GiB as '4 gib'";
  EXPECT_EQ(get_stream_output(5_TiB), "5 tib") << "[AbbreviatedLowercase] - Should display 5_TiB as '5 tib'";
  EXPECT_EQ(get_stream_output(6_PiB), "6 pib") << "[AbbreviatedLowercase] - Should display 6_PiB as '6 pib'";
  EXPECT_EQ(get_stream_output(7_EiB), "7 eib") << "[AbbreviatedLowercase] - Should display 7_EiB as '7 eib'";
  EXPECT_EQ(get_stream_output(8_ZiB), "8 zib") << "[AbbreviatedLowercase] - Should display 8_ZiB as '8 zib'";
  EXPECT_EQ(get_stream_output(9_YiB), "9 yib") << "[AbbreviatedLowercase] - Should display 9_YiB as '9 yib'";
  EXPECT_EQ(get_stream_output(10_RiB), "10 rib") << "[AbbreviatedLowercase] - Should display 10_RiB as '10 rib'";
  EXPECT_EQ(get_stream_output(11_QiB), "11 qib") << "[AbbreviatedLowercase] - Should display 11_QiB as '11 qib'";
}

GTEST_TEST(styles, full) {
  size::CURRENT_STYLE = size::Style::Long;
  EXPECT_EQ(get_stream_output(1_B), "1 Byte") << "[Long] - Should display 1_B as '1 Byte'";
  EXPECT_EQ(get_stream_output(2_B), "2 Bytes") << "[Long] - Should display 2_B as '2 Bytes'";
  EXPECT_EQ(get_stream_output(1_KB), "1 Kilobyte") << "[Long] - Should display 1_KB as '1 Kilobyte'";
  EXPECT_EQ(get_stream_output(2_KB), "2 Kilobytes") << "[Long] - Should display 2_KB as '2 Kilobytes'";
  EXPECT_EQ(get_stream_output(3_MB), "3 Megabytes") << "[Long] - Should display 3_MB as '3 Megabytes'";
  EXPECT_EQ(get_stream_output(4_GB), "4 Gigabytes") << "[Long] - Should display 4_GB as '4 Gigabytes'";
  EXPECT_EQ(get_stream_output(5_TB), "5 Terabytes") << "[Long] - Should display 5_TB as '5 Terabytes'";
  EXPECT_EQ(get_stream_output(6_PB), "6 Petabytes") << "[Long] - Should display 6_PB as '6 Petabytes'";
  EXPECT_EQ(get_stream_output(7_EB), "7 Exabytes") << "[Long] - Should display 7_EB as '7 Exabytes'";
  EXPECT_EQ(get_stream_output(8_ZB), "8 Zettabytes") << "[Long] - Should display 8_ZB as '8 Zettabytes'";
  EXPECT_EQ(get_stream_output(9_YB), "9 Yottabytes") << "[Long] - Should display 9_YB as '9 Yottabytes'";
  EXPECT_EQ(get_stream_output(10_RB), "10 Ronnabytes") << "[Long] - Should display 10_RB as '10 Ronnabytes'";
  EXPECT_EQ(get_stream_output(11_QB), "11 Quettabytes") << "[Long] - Should display 11_QB as '11 Quettabytes'";
  EXPECT_EQ(get_stream_output(1_KiB), "1 Kibibyte") << "[Long] - Should display 1_KiB as '1 Kibibyte'";
  EXPECT_EQ(get_stream_output(2_KiB), "2 Kibibytes") << "[Long] - Should display 2_KiB as '2 Kibibytes'";
  EXPECT_EQ(get_stream_output(3_MiB), "3 Mebibytes") << "[Long] - Should display 3_MiB as '3 Mebibytes'";
  EXPECT_EQ(get_stream_output(4_GiB), "4 Gibibytes") << "[Long] - Should display 4_GiB as '4 Gibibytes'";
  EXPECT_EQ(get_stream_output(5_TiB), "5 Tebibytes") << "[Long] - Should display 5_TiB as '5 Tebibytes'";
  EXPECT_EQ(get_stream_output(6_PiB), "6 Pebibytes") << "[Long] - Should display 6_PiB as '6 Pebibytes'";
  EXPECT_EQ(get_stream_output(7_EiB), "7 Exbibytes") << "[Long] - Should display 7_EiB as '7 Exbibytes'";
  EXPECT_EQ(get_stream_output(8_ZiB), "8 Zebibytes") << "[Long] - Should display 8_ZiB as '8 Zebibytes'";
  EXPECT_EQ(get_stream_output(9_YiB), "9 Yobibytes") << "[Long] - Should display 9_YiB as '9 Yobibytes'";
  EXPECT_EQ(get_stream_output(10_RiB), "10 Robibytes") << "[Long] - Should display 10_RiB as '10 Robibytes'";
  EXPECT_EQ(get_stream_output(11_QiB), "11 Quebibytes") << "[Long] - Should display 11_QiB as '11 Quebibytes'";
}

GTEST_TEST(styles, full_lowercase) {
  size::CURRENT_STYLE = size::Style::LongLowercase;
  EXPECT_EQ(get_stream_output(1_B), "1 byte") << "[LongLowercase] - Should display 1_B as '1 byte'";
  EXPECT_EQ(get_stream_output(2_B), "2 bytes") << "[LongLowercase] - Should display 2_B as '2 bytes'";
  EXPECT_EQ(get_stream_output(1_KB), "1 kilobyte") << "[LongLowercase] - Should display 1_KB as '1 kilobyte'";
  EXPECT_EQ(get_stream_output(2_KB), "2 kilobytes") << "[LongLowercase] - Should display 2_KB as '2 kilobytes'";
  EXPECT_EQ(get_stream_output(3_MB), "3 megabytes") << "[LongLowercase] - Should display 3_MB as '3 megabytes'";
  EXPECT_EQ(get_stream_output(4_GB), "4 gigabytes") << "[LongLowercase] - Should display 4_GB as '4 gigabytes'";
  EXPECT_EQ(get_stream_output(5_TB), "5 terabytes") << "[LongLowercase] - Should display 5_TB as '5 terabytes'";
  EXPECT_EQ(get_stream_output(6_PB), "6 petabytes") << "[LongLowercase] - Should display 6_PB as '6 petabytes'";
  EXPECT_EQ(get_stream_output(7_EB), "7 exabytes") << "[LongLowercase] - Should display 7_EB as '7 exabytes'";
  EXPECT_EQ(get_stream_output(8_ZB), "8 zettabytes") << "[LongLowercase] - Should display 8_ZB as '8 zettabytes'";
  EXPECT_EQ(get_stream_output(9_YB), "9 yottabytes") << "[LongLowercase] - Should display 9_YB as '9 yottabytes'";
  EXPECT_EQ(get_stream_output(10_RB), "10 ronnabytes") << "[LongLowercase] - Should display 10_RB as '10 ronnabytes'";
  EXPECT_EQ(get_stream_output(11_QB), "11 quettabytes") << "[LongLowercase] - Should display 11_QB as '11 quettabytes'";
  EXPECT_EQ(get_stream_output(1_KiB), "1 kibibyte") << "[LongLowercase] - Should display 1_KiB as '1 kibibyte'";
  EXPECT_EQ(get_stream_output(2_KiB), "2 kibibytes") << "[LongLowercase] - Should display 2_KiB as '2 kibibytes'";
  EXPECT_EQ(get_stream_output(3_MiB), "3 mebibytes") << "[LongLowercase] - Should display 3_MiB as '3 mebibytes'";
  EXPECT_EQ(get_stream_output(4_GiB), "4 gibibytes") << "[LongLowercase] - Should display 4_GiB as '4 gibibytes'";
  EXPECT_EQ(get_stream_output(5_TiB), "5 tebibytes") << "[LongLowercase] - Should display 5_TiB as '5 tebibytes'";
  EXPECT_EQ(get_stream_output(6_PiB), "6 pebibytes") << "[LongLowercase] - Should display 6_PiB as '6 pebibytes'";
  EXPECT_EQ(get_stream_output(7_EiB), "7 exbibytes") << "[LongLowercase] - Should display 7_EiB as '7 exbibytes'";
  EXPECT_EQ(get_stream_output(8_ZiB), "8 zebibytes") << "[LongLowercase] - Should display 8_ZiB as '8 zebibytes'";
  EXPECT_EQ(get_stream_output(9_YiB), "9 yobibytes") << "[LongLowercase] - Should display 9_YiB as '9 yobibytes'";
  EXPECT_EQ(get_stream_output(10_RiB), "10 robibytes") << "[LongLowercase] - Should display 10_RiB as '10 robibytes'";
  EXPECT_EQ(get_stream_output(11_QiB), "11 quebibytes") << "[LongLowercase] - Should display 11_QiB as '11 quebibytes'";
}

#pragma endregion

#pragma region Unit get_unit_via_Unit_enum
GTEST_TEST(Unit, get_unit_via_Unit_enum) {
  EXPECT_EQ(size::find_unit_pair(size::Unit::BYTE), size::units.at(0)) << "Should return size::units.at(0)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::KIBIBYTE), size::units.at(1)) << "Should return size::units.at(1)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::KILOBYTE), size::units.at(2)) << "Should return size::units.at(2)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::MEBIBYTE), size::units.at(3)) << "Should return size::units.at(3)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::MEGABYTE), size::units.at(4)) << "Should return size::units.at(4)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::GIBIBYTE), size::units.at(5)) << "Should return size::units.at(5)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::GIGABYTE), size::units.at(6)) << "Should return size::units.at(6)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::TEBIBYTE), size::units.at(7)) << "Should return size::units.at(7)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::TERABYTE), size::units.at(8)) << "Should return size::units.at(8)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::PEBIBYTE), size::units.at(9)) << "Should return size::units.at(9)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::PETABYTE), size::units.at(10)) << "Should return size::units.at(10)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::EXBIBYTE), size::units.at(11)) << "Should return size::units.at(11)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::EXABYTE), size::units.at(12)) << "Should return size::units.at(12)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::ZEBIBYTE), size::units.at(13)) << "Should return size::units.at(13)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::ZETTABYTE), size::units.at(14)) << "Should return size::units.at(14)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::YOBIBYTE), size::units.at(15)) << "Should return size::units.at(15)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::YOTTABYTE), size::units.at(16)) << "Should return size::units.at(16)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::ROBIBYTE), size::units.at(17)) << "Should return size::units.at(17)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::RONNABYTE), size::units.at(18)) << "Should return size::units.at(18)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::QUEBIBYTE), size::units.at(19)) << "Should return size::units.at(19)";
  EXPECT_EQ(size::find_unit_pair(size::Unit::QUETTABYTE), size::units.at(20)) << "Should return size::units.at(20)";
}

#pragma endregion
