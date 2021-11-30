#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/**
 * @brief {2,3] {5,4] {6,4] {6,7]
 */
class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [&](const vector<int> &v1, const vector<int> &v2) -> bool {
           if (v1[0] == v2[0])
             return v1[1] < v2[1];
           return v1[0] < v2[0];
         });
    int lens = envelopes.size();
    // vector<int> dp(lens, 1);
    auto dp = new int[lens];

    for (int i = 0; i < lens; i++)
      dp[i] = 1;

    for (int i = 1; i < lens; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (envelopes[i][0] > envelopes[j][0] &&
            envelopes[i][1] > envelopes[j][1] && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }

    int max = dp[0];
    for (int i = 1; i < lens; i++) {
      if (dp[i] > max)
        max = dp[i];
    }
    delete[] dp;
    return max;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> vv{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  EXPECT_EQ(s.maxEnvelopes(vv), 3);
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<vector<int>> vv{{1, 1}, {1, 1}, {1, 1}};
  EXPECT_EQ(s.maxEnvelopes(vv), 1);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<vector<int>> vv{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400},
                         {5, 250}, {6, 370}, {6, 360}, {7, 380}};

  EXPECT_EQ(s.maxEnvelopes(vv), 5);
}
