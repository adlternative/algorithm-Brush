#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int max_val = 0;
    vector<vector<int>> dp(row, vector<int>(col));

    for (int i = 0; i < row; ++i) {
      dp[i][0] = matrix[i][0] - '0';
      max_val = max(max_val, dp[i][0]);
    }
    for (int j = 0; j < col; ++j) {
      dp[0][j] = matrix[0][j] - '0';
      max_val = max(max_val, dp[0][j]);
    }
    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
        } else {
          dp[i][j] = 0;
        }

        if (max_val < dp[i][j])
          max_val = dp[i][j];
      }
    }
    return max_val * max_val;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<char>> vv{{'1', '0', '1', '0', '0'},
                          {'1', '0', '1', '1', '1'},
                          {'1', '1', '1', '1', '1'},
                          {'1', '0', '0', '1', '0'}};
  EXPECT_EQ(s.maximalSquare(vv), 4);
}
