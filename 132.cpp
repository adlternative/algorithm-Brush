#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  // bool isReply(string s) {
  //   for (size_t i = 0; i < s.size() / 2; i++) {
  //     if (s[i] != s[s.size() - i])
  //       return false;
  //   }
  //   return true;
  // }
  Solution() : cnt_(0) {}
  int cnt_;
  vector<vector<bool>> dp;
  // vector<vector<string>> ret;
  queue<int> q;
  int len;

  int minCut(string s) {
    if (s.empty())
      return cnt_;
    len = s.size();
    dp.assign(len + 1, vector<bool>(len + 1, false));
    /* 预处理 */
    for (size_t i = 0; i < len; i++) {
      dp[i][i + 1] = true;
      dp[i][i] = true;
    }
    for (int i = len - 1; i >= 0; i--) {
      for (int j = len + 1; j >= i + 2; j--) {
        dp[i][j] = s[i] == s[j - 1] && dp[i + 1][j - 1];
      }
    }

    for (size_t i = 0; i < len; i++) {
      dp[i][i] = false;
    }
    vector<int> f(len + 1, INT_MAX);
    for (int i = 0; i < len + 1; ++i) {
      if (dp[0][i]) {
        f[i] = 0;
      } else {
        for (int j = 0; j < i; ++j) {
          if (dp[j][i]) {
            f[i] = min(f[i], f[j] + 1);
          }
        }
      }
    }

    // for (auto &&i : f) {
    //   std::cout << i << std::endl;
    // }

    return f[len];

    /* 可达矩阵 */
    // for (size_t i = 0; i < len + 1; i++) {
    //   for (size_t j = 0; j < len + 1; j++) {
    //     std::cout << dp[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    // std::cout << std::endl;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout
      << s.minCut(
             "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostp"
             "qczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucx"
             "pobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohz"
             "nkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhg"
             "xukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlg"
             "nfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfw"
             "hxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnw"
             "wqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp")
      << std::endl;
  // s.partition("aab");

  return 0;
}
