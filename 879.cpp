#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    int lens = group.size();
    vector<vector<vector<int>>> dp(
        lens + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    /* 方法数 group 数 人数 最低利润 */

    /* 最多 j 个人 */
    for (int j = 0; j <= n; j++) {
      dp[0][j][0] = 1;
    }
    for (int i = 1; i <= lens; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= minProfit; k++) {
          if (j < group[i - 1]) {
            dp[i][j][k] = dp[i - 1][j][k];
          } else {
            dp[i][j][k] =
                (dp[i - 1][j][k] +
                 dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]) %
                (int)(1e9 + 7);
          }
        }
      }
    }

    return dp[lens][n][minProfit];
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
