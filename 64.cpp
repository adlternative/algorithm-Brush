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
  int minPathSum(vector<vector<int>> &grid) {
    size_t row = grid.size();
    size_t col = grid[0].size();
    if (!row | !col)
      return 0;
    int dp[row][col];
    // memset(dp, INT_MAX, sizeof(dp));
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
        if (!i && !j)
          dp[i][j] = grid[i][j];
        else if (!i && j) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (i && !j) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = INT_MAX;
        }
      }
    }
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
        if (i && j) {
          // std::cout << dp[i - 1][j] + grid[i][j] << "?>" << std::endl;
          // std::cout << dp[i][j] << "!>" << std::endl;
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
        }
      }
    }
    // for (size_t i = 0; i < row; i++) {
    //   for (size_t j = 0; j < col; j++) {
    //     std::cout << dp[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    // std::cout << std::endl;

    return dp[row - 1][col - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> vv;
  vv.emplace_back(vector<int>{1, 3, 1});
  vv.emplace_back(vector<int>{1, 5, 1});
  vv.emplace_back(vector<int>{4, 2, 1});
  auto ret = s.minPathSum(vv);
  std::cout << ret << std::endl;
  return 0;
}