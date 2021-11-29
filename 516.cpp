#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int longestPalindromeSubseq(string_view s) {
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len - 1; i++) {
      dp[i][i] = 1;
      if (s[i] == s[i + 1])
        dp[i][i + 1] = 2;
    }
    dp[len - 1][len - 1] = 1;

    for (int i = len; i >= 0; i--) {
      for (int j = i + 1; j < len; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][len - 1];
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.longestPalindromeSubseq("bbbab"), 4);
  EXPECT_EQ(s.longestPalindromeSubseq("cbbd"), 2);
  EXPECT_EQ(s.longestPalindromeSubseq("a"), 1);
}
