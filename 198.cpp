#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int rob(vector<int> &nums) {
    /* dp[i] = max money until index i */
    int ret = 0;
    int lens = nums.size();
    int dp[lens][2];
    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for (int i = 1; i < lens; i++) {
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[lens - 1][0], dp[lens - 1][1]);
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
