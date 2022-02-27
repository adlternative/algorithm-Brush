#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int reverse(int x) {
    auto str = to_string(x);
    auto lens = str.size();
    long long ret = 0;

    long long base = 1;
    bool reverse = false;
    for (int i = 0; i < lens; i++) {
      if (str[i] == '-') {
        reverse = true;
        continue;
      }
      ret += (str[i] - '0') * base;
      if (((ret / 10) > (INT_MAX / 10)) || ((ret / 10) < (INT_MIN / 10))) {
        ret = 0;
        break;
      }
      base *= 10;
    }

    if (reverse)
      ret = -ret;

    return (int)ret;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.reverse(-123), 321);
}
