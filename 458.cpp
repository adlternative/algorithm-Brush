#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
