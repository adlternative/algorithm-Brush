#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      }
    }
    return dp[len1][len2];
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
