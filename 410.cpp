#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    /* i:最后一个坐标,  j:块数  dp:所求的最小最大值 */
    /* dp[i][j] = min(dp[i][j],dp[k][j-1],sum[k+1,i]) */
    /* [0, k] 分成  j-1 块 剩下的 [k + 1, i]作为一片 k<i */
    int lens = nums.size();
    int dp[lens][lens];

    dp[0][1] = nums[0];
    for (int i = 1; i < lens; i++) {
      // 前缀和
      dp[i][1] = dp[i - 1][1] + nums[i];
    }

    /* 一块不能切成两份  所以 i >= j */

    for (int i = 1; i < lens; i++) {
      for (int j = 2; j <= i; j++) {
        dp[i][j] = INT_MAX;
        for (int k = j - 2; k + 1 <= i; k++) {
          dp[i][j] = min(dp[i][j], max(dp[k][j - 1],dp[i][1] - dp[k][1]));
        }
      }
    }

    return dp[lens - 1][m];
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
