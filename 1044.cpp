#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  unordered_map<string_view, int> s2c;

  /* 会超时 */
  string check(string_view s, int sub_len) {
    string ret;
    int lens = s.size();
    for (int i = 0; i <= lens - sub_len; i++) {
      auto slice = s.substr(i, sub_len);
      auto iter = s2c.find(slice);
      if (iter != s2c.end() && iter->second >= 1) {
        ret = slice;
        break;
      }
      s2c[slice]++;
    }
    s2c.clear();
    return ret;
  }

  string longestDupSubstring(string s) {
    /* 二分答案 + 滑动窗口 */
    string ret;
    int lens = s.size();
    int l = 2, h = (lens + 1) / 2;
    while (l <= h) {
      int m = (l + h) / 2;
      auto get = check(s, m);
      if (get.empty()) {
        h--;
      } else {
        ret = std::move(get);
        l++;
      }
    }

    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
