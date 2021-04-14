#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    size_t row = obstacleGrid.size();
    size_t col = obstacleGrid[0].size();
    if ((row && col && obstacleGrid[0][0] == 1) | !row | !col)
      return 0;
    int dp[row][col];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
        if (obstacleGrid[i][j])
          continue;
        if (i && j)
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        else if (i)
          dp[i][j] = dp[i - 1][j];
        else if (j)
          dp[i][j] = dp[i][j - 1];
      }
    }
    return dp[row - 1][col - 1];
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> vv;
  vv.emplace_back(vector<int>{0, 0, 0});
  vv.emplace_back(vector<int>{0, 1, 0});
  vv.emplace_back(vector<int>{0, 0, 0});
  auto ret = s.uniquePathsWithObstacles(vv);
  std::cout << ret << std::endl;
  return 0;
}
