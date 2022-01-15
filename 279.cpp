#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
/* 零一背包 */
class Solution {
public:
  int numSquares(int n) {
    int dp[n + 1];
    for (int i = 2; i <= n; i++)
      dp[i] = INT_MAX;


    for (int i = 1; i <= n; i++) {
      for (int j = 1; i - j * j >= 0; j++) {
        if (i == j * j)
          dp[i] = 1;
        else
          dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.numSquares(12), 3);
}
