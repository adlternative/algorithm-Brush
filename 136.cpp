#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (auto num : nums) {
      ret ^= num;
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
