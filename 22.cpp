#include <array>
#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> **dp = new vector<string> *[n + 1];
    vector<string> ret;

    for (int i = 0; i < n + 1; i++) {
      dp[i] = new vector<string>[n + 1];
      /* dp[0][4]= "((((" */
    }
    for (int j = 1; j < n + 1; j++) {
      dp[0][j].emplace_back(j, '(');
    }

    /* j = left  i = right */
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        /* dp[1][1] = dp[0][1] + ')' */
        if (i == j)
          for (auto &&str : dp[i - 1][j]) {
            dp[i][j].emplace_back(str + ')');
          }
        else {
          for (auto &&str : dp[i - 1][j]) {
            dp[i][j].emplace_back(str + ')');
          }
          for (auto &&str : dp[i][j - 1]) {
            dp[i][j].emplace_back(str + '(');
          }
        }
        // std::cout << i << j << std::endl;
      }
    }
    ret.swap(dp[n][n]);
    for (int i = 0; i < n + 1; i++) {
      delete[] dp[i];
    }
    delete[] dp;
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.generateParenthesis(3);
  for (auto &&i : ret)
    std::cout << i << std::endl;
  return 0;
}
