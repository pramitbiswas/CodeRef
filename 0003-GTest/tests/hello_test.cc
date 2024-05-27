#include <gtest/gtest.h>
#include "optArgParse.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(GetArgParse, BasicAssertions) {
  // arrange
  std::unordered_map<char, std::string> ref_map, map;
  ref_map['a'] = "15";
  ref_map['v'] = "";

  int argc = 3;
  char *argv_ele[] = { (char *)"./optarg_gtest", (char *)"-v", (char *)"-a15" };
  char **argv = argv_ele;

  // act
  opt_arg_parse(argc, argv, map);

  // assert
  // Expect equality.
  EXPECT_EQ(ref_map, map);
}





// int main(int argc, char **argv)
// {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
