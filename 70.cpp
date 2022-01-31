#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;

    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    /* dp[3] = dp[2] + dp[1] */
    /* dp[4] = dp[3] + dp[2] */

    for (int i = 3; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.climbStairs(2), 2);
}
