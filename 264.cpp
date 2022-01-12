#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int nthUglyNumber(int n) {
    int dp[n];
    int p1 = 0, p2 = 0, p3 = 0;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
      dp[i] = min(min(dp[p1] * 2, dp[p2] * 3), dp[p3] * 5);
      if (dp[i] == dp[p1] * 2)
        p1++;
      if (dp[i] == dp[p2] * 3)
        p2++;
      if (dp[i] == dp[p3] * 5)
        p3++;
    }
    return dp[n - 1];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.nthUglyNumber(10), 12);
}
