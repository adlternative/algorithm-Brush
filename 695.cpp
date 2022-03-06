#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

int direct[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
class Solution {
public:
  bool overofrange(int i, int j) { return i >= r || i < 0 || j >= c || j < 0; }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    int ret = 0;
    for (int k = 0; k < 4; k++) {
      int ni = i + direct[k][0];
      int nj = j + direct[k][1];
      if (!overofrange(ni, nj) && grid[ni][nj]) {
        grid[ni][nj] = 0;
        ret += 1 + dfs(grid, ni, nj);
      }
    }
    return ret;
  }

  int r;
  int c;
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ret = 0;
    r = grid.size();
    c = grid[0].size();

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j]) {
          grid[i][j] = 0;
          int count = 1 + dfs(grid, i, j);
          ret = max(ret, count);
        }
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
