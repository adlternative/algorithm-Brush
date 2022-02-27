#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int lens = stations.size();
    vector<vector<long>> dp(
        lens + 1,
        vector<long>(lens + 1)); /* 从 0 ~ i 选取 j 个  得到的最大距离 */
    for (int i = 0; i <= lens; i++)
      dp[i][0] = startFuel;

    for (int i = 1; i <= lens; i++) {
      for (int j = 1; j <= i; j++) {
        if (dp[i - 1][j] >= stations[i - 1][0])
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (dp[i - 1][j - 1] >= stations[i - 1][0])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]);
      }
    }
    for (int i = 0; i <= lens; i++) {
      if (dp[lens][i] >= target) {
        return i;
      }
    }
    return -1;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
