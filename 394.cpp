#include <bits/stdc++.h>
#include <cctype>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  string decodeString(string_view s) {
    deque<string> strs;
    int tmp_value = 0;
    string tmp_string;
    int lens = s.size();

    for (auto i = 0; i < lens; i++) {
      char c = s[i];

      if (isdigit(c)) {
        string tmp;
        while (isdigit(c)) {
          tmp.push_back(c);
          c = s[++i];
        }
        --i;
        strs.push_back(std::move(tmp));
      } else if (c == '[') {
        strs.push_back(string(1, c));
      } else if (c == ']') {
        string tmp;
        string ss;
        int len_strs = strs.size();
        int idx = len_strs - 1;
        while (strs[idx] != "[")
          idx--;
        for (auto i = idx + 1; i < len_strs; i++)
          tmp += strs[i];

        strs.resize(idx);
        int count = stoi(strs.back());
        strs.pop_back();
        for (int i = 0; i < count; i++)
          ss += tmp;
        strs.push_back(std::move(ss));
      } else {
        strs.push_back(string(1, c));
      }
    }
    string result;
    for (const auto &s : strs)
      result += s;
    return result;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.decodeString("3[a2[c]]"), "accaccacc");
}
