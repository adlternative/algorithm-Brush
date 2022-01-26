#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int backToOrigin(int n) {
    /* 次数 期望走到的坐标 -> 总可能次数 */
    int dp[n + 1][10];
    dp[0][0] = 1;
    for (int i = 1; i < 10; i++)
      dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 10; j++) {
        dp[i][j] = dp[i - 1][(j + 9) % 10] + dp[i - 1][(j + 1) % 10];
      }
    }
    return dp[n][0];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.backToOrigin(2), 2);
}
