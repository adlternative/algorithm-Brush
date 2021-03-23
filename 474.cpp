#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, '\0', sizeof(dp));
    int vlen = strs.size();
    vector<pair<int, int>> v_(vlen);
    for (size_t i = 0; i < vlen; i++) {
      v_[i].first = std::count(strs[i].begin(), strs[i].end(), '0');
      v_[i].second = std::count(strs[i].begin(), strs[i].end(), '1');
      // std::cout << v_[i].first << v_[i].second << std::endl;
    }
    for (int k = 0; k < vlen; k++) {
      for (int i = m; i >= v_[k].first; i--) {
        for (int j = n; j >= v_[k].second; j--) {
          // std::cout << "?" << k << "?" << i << "?" << j << std::endl;
          dp[i][j] = max(dp[i - v_[k].first][j - v_[k].second] + 1, dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int ret = s.findMaxForm(strs, 5, 3);
  std::cout << ret << std::endl;
  return 0;
}
