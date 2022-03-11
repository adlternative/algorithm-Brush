#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  string convertToBase7(int num) {
    string ret;
    int d = num;

    while (d) {
      ret.push_back(d % 7 + '0');
      d /= 7;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
