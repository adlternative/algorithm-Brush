#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/* dp */

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    auto lens = prices.size();
    if (k == 0 || lens == 0)
      return 0;
    int dp[lens][k + 1][2];
    memset(dp, 0, sizeof(dp));
    /*
      第 i 天 第 j 笔交易
      0 手上无股票
      1 手上有股票

      今天没有股票 = 昨天也没有股票 或者 今天卖了股票
      dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1] + prices[i]);
      今天有股票 = 昨天有股票 或者 今天买了股票
      dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][1] - prices[i]);
    */

    /* 第一天 2 笔以上的交易错误*/
    for (int i = 2; i <= k; i++) {
      dp[0][i][1] = INT_MIN;
    }
    /* 没有交易却有股票 */
    for (int i = 0; i < lens; i++) {
      dp[i][0][1] = INT_MIN;
    }
    dp[0][1][1] = -prices[0];

    for (int i = 1; i < lens; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }
    /* 返回最后一天 最大交易次数 时 卖出状态下的最大钱数 */
    int maxs = 0;
    for (int i = 1; i <= k; i++) {
      maxs = max(maxs, dp[lens - 1][i][0]);
    }
    return maxs;
  }
};

TEST(Solution, isMatch0) {
  Solution s;

  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  EXPECT_EQ(s.maxProfit(2, prices), 6);
}

TEST(Solution, isMatch) {
  Solution s;
  vector<int> prices = {3, 2, 6, 5, 0, 3};
  EXPECT_EQ(s.maxProfit(2, prices), 7);
}

TEST(Solution, isMatch2i) {
  Solution s;

  vector<int> prices = {2, 4, 1};
  EXPECT_EQ(s.maxProfit(2, prices), 2);
}