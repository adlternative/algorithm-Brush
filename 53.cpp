#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int lens = nums.size();
    vector<int> dp(lens, 0);
    dp[0] = nums[0];
    int max_value = dp[0];
    for (int i = 1; i < lens; i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      if (dp[i] > max_value)
        max_value = dp[i];
    }
    return max_value;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
