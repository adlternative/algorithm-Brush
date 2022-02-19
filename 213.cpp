#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int rob(vector<int> &nums, int begin, int end) {
    int lens = end - begin;
    if (!lens)
      return 0;

    int dp[lens][2];
    dp[0][0] = 0;
    dp[0][1] = nums[begin];

    for (int i = 1; i < lens; i++) {
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[begin + i]);
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[lens - 1][0], dp[lens - 1][1]);
  }

  int rob(vector<int> &nums) {
    /* dp[i] = max money until index i */
    int lens = nums.size();
    if (lens == 1)
      return nums[0];
    else if (lens == 2)
      return 0;
    return nums[0] + rob(nums, 2, lens - 1) + rob(nums, 1, lens);
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
