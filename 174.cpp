#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int row = dungeon.size();
    int col = dungeon[0].size();
    int dp[row][col];
    dp[row - 1][col - 1] = -dungeon[row - 1][col - 1];
    for (int i = row - 2; i >= 0; i--) {
      dp[i][col - 1] = max(0, dp[i + 1][col - 1] - dungeon[i][col - 1]);
    }

    for (int i = col - 2; i >= 0; i--) {
      dp[row - 1][i] = max(0, dp[row - 1][i + 1] - dungeon[row - 1][i]);
    }

    for (int i = row - 2; i >= 0; i--) {
      for (int j = col - 2; j >= 0; j--) {
        dp[i][j] = max(0, min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]);
      }
    }
    return dp[0][0] + 1;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
