#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

class Solution {
public:
  bool check1(const vector<string> &v) { return v.size() < 4; }
  bool check2(string &s, char c) {
    int len = s.size();

    if (len == 1) {
      if (s[0] == '0')
        return false;
      return true;
    } else if (len == 2) {
      if (s[0] == '0')
        return false;
      else if (s[0] == '1') {
        return true;
      } else if (s[0] == '2') {
        if (s[1] == '5')
          return c >= '0' && c <= '5';
        else if (s[1] > '5')
          return false;
        else
          return true;
      } else {
        return false;
      }
    } else if (len >= 3) {
      return false;
    } else {
      return false;
    }
  }
  vector<string> restoreIpAddresses(string s) {
    // vector<vector<string>> dp;
    vector<string> ret;
    int len = s.size();

    if (!len)
      return ret;
    auto dp = new vector<vector<string>>[len];

    string str(1, s[0]);

    vector<string> v;
    v.push_back(std::move(str));
    dp[0].push_back(std::move(v));

    for (int i = 1; i != len; i++) {
      // dp[i] =dp[i-1] + something
      vector<vector<string>> newLevel;
      /* 1. 后 append */
      for (auto vec : dp[i - 1]) {
        if (check1(vec)) {
          vec.emplace_back(string{s[i]});
          newLevel.push_back(std::move(vec));
        }
      }
      for (auto vec : dp[i - 1]) {
        auto &str = vec.back();
        if (check2(str, s[i])) {
          str.push_back(std::move(s[i]));
          newLevel.push_back(std::move(vec));
        }
      }
      dp[i] = std::move(newLevel);
    }
    for (auto &&vec : dp[len - 1]) {
      if (vec.size() == 4) {
        string ip;
        for (auto &&str : vec) {
          ip += str + ".";
        }
        ip.pop_back();
        ret.push_back(std::move(ip));
      }
    }
    delete[] dp;
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.restoreIpAddresses("101023");
  for (auto &&ip : ret) {
    std::cout << ip << std::endl;
  }
  return 0;
}
