#include "gtest/gtest.h"

namespace {
int Add(int x, int y) {
  return x + y;
}
} // namespace

TEST(BasicTest, TestAdd) {
  EXPECT_EQ(10, Add(10, 0));
  EXPECT_EQ(0, Add(-10, 10));
}
