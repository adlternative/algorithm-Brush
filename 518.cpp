#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (auto &coin : coins) {
      for (int i = coin; i <= amount; i++)
        dp[i] += dp[i - coin];
    }
    return dp[amount];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> coins{1, 2, 5};
  EXPECT_EQ(s.change(5, coins), 4);
}
