#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int minInsertions(string_view s) {
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len - 1; i++) {
      if (s[i] != s[i + 1])
        dp[i][i + 1] = 1;
    }
    for (int i = len - 2; i >= 0; i--) {
      for (int j = i + 1; j < len; j++) {
        if (s[i] != s[j])
          dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
        else
          dp[i][j] = dp[i + 1][j - 1];
      }
    }
    return dp[0][len - 1];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.minInsertions("mbadm"), 2);
  EXPECT_EQ(s.minInsertions("g"), 0);
  EXPECT_EQ(s.minInsertions("leetcode"), 5);
  EXPECT_EQ(s.minInsertions("no"), 1);
}
