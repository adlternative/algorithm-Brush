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

  int len;
  vector<vector<bool>> dp;
  vector<vector<string>> ret;
  vector<string> vs;
  void dfs(const string &s, int firstPartLen) {
    // while (firstPartLen != len + 1 && !dp[0][firstPartLen])
    //   firstPartLen++;
    // vs.push_back(s.substr(0, firstPartLen));
    if (firstPartLen == len) {
      ret.push_back(vs);
      return;
    }
    for (size_t j = firstPartLen + 1; j < len + 1; j++) {
      if (dp[firstPartLen][j]) {
        vs.push_back(s.substr(firstPartLen, j - firstPartLen));
        dfs(s, j);
        vs.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    if (s.empty())
      return ret;
    len = s.size();
    dp.assign(len + 1, vector<bool>(len + 1, false));
    /* 预处理 */
    for (size_t i = 0; i < len; i++) {
      dp[i][i + 1] = true;
      dp[i][i] = true;
    }
    /* "bb" len=2 [0][2] */
    // for (int i = 0; i < len - 1; i++) {
    //   for (int j = i + 2; j < len + 1; j++) {
    //     if (i == 0 && j == 4)
    //       std::cout << "?" << (s[i] == s[j - 1] )<< (dp[1][3]) << std::endl;
    //     dp[i][j] = s[i] == s[j - 1] && dp[i + 1][j - 1];
    //   }
    // }
    for (int i = len - 1; i >= 0; i--) {
      for (int j = len + 1; j >= i + 2; j--) {
        dp[i][j] = s[i] == s[j - 1] && dp[i + 1][j - 1];
        /* code */
      }
    }

    for (size_t i = 0; i < len; i++) {
      dp[i][i] = false;
    }
    // for (size_t i = 0; i < len; i++) {
    //   assert(dp[i][1 + i]);
    // }
    // assert(dp[1][3]);
    // assert(dp[0][4]);

    // for (size_t i = 0; i < len + 1; i++) {
    //   for (int j = 0; j < len + 1; j++) {
    //     std::cout << dp[i][j];
    //   }
    //   std::cout << std::endl;
    // }
    // std::cout << std::endl;

    dfs(s, 0);

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // s.partition("aab");
  auto ret = s.partition("abbab");
  for (size_t i = 0; i < ret.size(); i++) {
    for (size_t j = 0; j < ret[i].size(); j++) {
      std::cout << ret[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
