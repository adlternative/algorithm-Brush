#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

int direct[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

class Solution {
  int r;
  int c;

public:
  bool check(int i, int j) { return i < r && i >= 0 && j < c && j >= 0; }

  int dfs(vector<vector<int>> &matrix, int i, int j,
          vector<vector<int>> &memo) {
    int ret = 1;

    for (int k = 0; k < 4; k++) {
      int newi = i + direct[k][0];
      int newj = j + direct[k][1];
      if (!check(newi, newj) || matrix[newi][newj] <= matrix[i][j])
        continue;

      ret = max(ret, memo[newi][newj] ? memo[newi][newj] + 1
                                      : dfs(matrix, newi, newj, memo) + 1);
    }

    memo[i][j] = ret;
    return ret;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    r = matrix.size();
    c = matrix[0].size();
    vector<vector<int>> memo(r, vector<int>(c));
    int ret;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        ret = max(ret, memo[i][j] ? memo[i][j] : dfs(matrix, i, j, memo));
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
