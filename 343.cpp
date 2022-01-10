#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    if (n == 1)
      return dp[n];
    dp[2] = 1;
    if (n == 2)
      return dp[n];
    dp[3] = 2;

    for (int i = 4; i <= n; i++)
      for (int j = 1; j <= i / 2; j++)
        dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
    return dp[n];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.integerBreak(10), 36);
  EXPECT_EQ(s.integerBreak(2), 1);
}
