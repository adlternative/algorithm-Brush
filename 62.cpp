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
  int uniquePaths(int m, int n) {
    int dp[m][n];
    dp[0][0] = 1;

    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (j >= 1 && i >= 1)
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        else if (j >= 1)
          dp[i][j] = dp[i][j - 1];
        else if (i >= 1)
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.uniquePaths(3,7) << std::endl;
  return 0;
}
