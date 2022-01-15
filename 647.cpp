#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int countSubstrings(string_view s) {
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, 0));
    int ret = 0;

    for (int i = len - 1; i >= 0; --i) {
      for (int j = i; j < len; ++j) {
        if (i == j)
          dp[i][j] = true;
        else if (i + 1 == j)
          dp[i][j] = s[i] == s[j];
        else
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        if (dp[i][j])
          ret++;
      }
    }
    return ret;
    // return dp[0][len];
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.countSubstrings("aaa"), 6);
}
