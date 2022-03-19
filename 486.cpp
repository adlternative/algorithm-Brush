#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    int lens = nums.size();
    vector<vector<int>> dp(lens, vector<int>(lens));
    for (int i = lens - 1; i >= 0; i--) {
      for (int j = i; j < lens; j++) {
        if (i == j) {
          dp[i][j] = nums[i];
        } else {
          dp[i][j] = max(nums[j] - dp[i][j - 1], nums[i] - dp[i + 1][j]);
        }
      }
    }
    return dp[0][lens - 1] > 0;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 5, 2};
  EXPECT_EQ(s.PredictTheWinner(v), false);
  v = {1, 5, 233, 7};
  EXPECT_EQ(s.PredictTheWinner(v), true);
}
