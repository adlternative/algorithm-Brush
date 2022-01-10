#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool wordBreak(string_view s, vector<string> &wordDict) {
    unordered_set<string_view> wordMap;
    int len = s.size();
    for (auto &word : wordDict)
      wordMap.insert(word);
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    /* dp[i] = dp[j] + check(s[j..i-1]) */
    for (int i = 1; i < len + 1; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && wordMap.find(s.substr(j, i - j)) != wordMap.end())
          dp[i] = true;
      }
    }

    return dp[len];
  }
};
// for (int i = 1; i < len + 1; i++)
//   printf("%s ", dp[i] ? "True" : "False");
// printf("\n");

TEST(Solution, isMatch) {
  Solution s;
  vector<string> wordDict{"leet", "code"};
  EXPECT_EQ(s.wordBreak("leetcode", wordDict), true);
}
