#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int numDecodings(string_view s) {
    int len = s.size();
    unordered_set<string> wordMap;
    for (int i = 1; i <= 26; i++)
      wordMap.insert(to_string(i));
    vector<int> dp(len + 1, 0);
    dp[0] = 1;

    /* dp[i] = dp[j] + check(s[j..i-1]) */
    for (int i = 1; i < len + 1; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && wordMap.find(string(s.substr(j, i - j))) != wordMap.end())
          dp[i] += dp[j];
      }
    }
    return dp[len];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.numDecodings("12"), 2);
  EXPECT_EQ(s.numDecodings("226"), 3);
  EXPECT_EQ(s.numDecodings("06"), 0);
}
