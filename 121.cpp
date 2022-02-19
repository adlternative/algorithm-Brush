#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int lens = prices.size();
    int dp[lens][2]; /* 0 代表没 1 代表有 */
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < lens; i++) {
      dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
      dp[i][1] = max(-prices[i], dp[i - 1][1]);
    }
    return dp[lens - 1][0];
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
