#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int lenp = p.size();
    int lens = s.size();
    vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
    /*初始化状态 */
    dp[0][0] = true;
    /* dp[0][1,lenp] */
    for (int i = 1; i <= lenp; i++) {
      if (p[i - 1] == '*') {
        dp[0][i] = true;
      } else {
        break;
      }
    }
    for (int i = 1; i <= lens; i++) {
      dp[i][0] = false;
    }

    for (int i = 1; i <= lens; i++) {
      for (int j = 1; j <= lenp; j++) {
        if (p[j - 1] >= 'a' && p[j - 1] <= 'z') {
          dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
        } else if (p[j - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
      }
    }

    return dp[lens][lenp];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.isMatch("abc", "a?c"), true);
  EXPECT_EQ(s.isMatch("abc", "a??c"), false);
  EXPECT_EQ(s.isMatch("abcdef", "a*c?ef"), true);
  EXPECT_EQ(s.isMatch("", "***"), true);
}
