#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  bool match(string &s, string &p, int i, int j) {
    if (i == 0) {
      return false;
    }
    if (p[j - 1] == '.')
      return true;
    return p[j - 1] == s[i - 1];
  }

  bool isMatch(string s, string p) {
    int lens = s.size();
    int lenp = p.size();
    vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= lens; i++) {
      for (int j = 1; j <= lenp; j++) {
        if (p[j - 1] == '*') {
          if (match(s, p, i, j - 1)) {
            /* assert(i>=1) */
            if (j >= 2)
              dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
            else
              dp[i][j] = dp[i - 1][j];
          } else {
            if (j >= 2)
              dp[i][j] = dp[i][j - 2];
          }
        } else {
          if (match(s, p, i, j)) {
            /* assert(i>=1) */
            if (j >= 1)
              dp[i][j] = dp[i - 1][j - 1];
          }
        }
      }
    }
    return dp[lens][lenp];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.isMatch("ab", ".*"), true);
  EXPECT_EQ(s.isMatch("aab", "c*a*b"), true);
}
