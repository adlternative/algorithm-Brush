#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool canCross(vector<int> &stones) {
    int lens = stones.size();
    vector<vector<bool>> dp(lens, vector<bool>(lens));
    dp[0][0] = true;

    for (int i = 1; i < lens; i++) {
      /* 遍历之前走过的所有石头 */
      for (int j = i - 1; j >= 0; j--) {
        int k = stones[i] - stones[j];
        if (k > j + 1)
          break;
        dp[i][k] = dp[j][k] || dp[j][k + 1] || dp[j][k - 1];
        if (i == lens - 1 && dp[i][k]) {
          return true;
        }
      }
    }
    return false;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
