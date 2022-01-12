#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    /*
        Y + X = S = 5
        Y - X = T = 3
        Y = 4 X = 1
    */
    int lens = nums.size();
    int sum = 0;
    for (auto i : nums)
      sum += i;

    int diff = sum - target;
    if (diff < 0 || diff % 2)
      return 0;
    int neg = (sum - target) / 2;

    int dp[lens + 1][neg + 1]; //<最大坐标 i , 总和 j> -> 方案数量 dp[i][j]
    dp[0][0] = 1;
    for (int i = 1; i <= neg; i++)
      dp[0][i] = 0;
    for (int i = 1; i <= lens; i++) {
      for (int j = 0; j <= neg; j++) {
        if (nums[i - 1] <= j)
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[lens][neg];
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
