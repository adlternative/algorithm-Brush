#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  string makeLargestSpecial(string_view s) {
    int lens = s.size();
    int count = 0;
    vector<string> vv;
    string ret;
    int begin = 0;

    if (!lens)
      return ret;

    for (int i = 0; i < lens; i++) {
      if (s[i] == '1')
        count++;
      else
        count--;
      if (!count) {
        string tmp(1, '1');
        tmp += makeLargestSpecial(s.substr(begin + 1, i - begin - 1)) + '0';
        vv.emplace_back(tmp);
        begin = i + 1;
      }
    }
    sort(vv.begin(), vv.end(), greater<string>());
    for (const string &i : vv) {
      ret += i;
    }
    return ret;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.makeLargestSpecial("11011000"), "11100100");
}
