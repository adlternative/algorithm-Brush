#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int len = strs.size();

    for (int i = 0;; i++) {
      if (strs[0].size() <= i) {
        return strs[0].substr(0, i);
      }

      auto c = strs[0][i];
      bool same = true;
      for (int j = 1; j < len; j++) {
        /* 超出长度 或者 字符不同 */
        if (strs[j].size() <= i || strs[j][i] != c) {
          same = false;
          break;
        }
      }
      /* 出现了不同/全相同继续 */
      if (!same) {
        return strs[0].substr(0, i);
      }
    }
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
