#include <bits/stdc++.h>
#include <climits>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {

public:
  int maxProduct(vector<int> &nums) {
    int max_product = INT_MIN;
    int lens = nums.size();
    vector<vector<int>> dp(lens, vector<int>(2));
    dp[0][0] = nums[0];
    dp[0][1] = nums[0];

    for (int i = 1; i < lens; i++) {
      /* max = max(nums[i], dp[i-1][1] * nums[i], dp[i - 1][0] * nums[i]); */
      dp[i][0] =
          max(dp[i - 1][0] * nums[i], max(nums[i], dp[i - 1][1] * nums[i]));
      dp[i][1] =
          min(dp[i - 1][1] * nums[i], min(nums[i], dp[i - 1][0] * nums[i]));
      if (max_product < dp[i][0])
        max_product = dp[i][0];
    }
    return max_product;
  }
};

/*


正数最大值
dp[i][0] = nums[i] > 0 ? nums[i] * dp[i-1][0] : nums[i] * dp[i-1][1] ;
负数最大值
dp[i][1] = nums[i] > 0 ? nums[i] * dp[i-1][1] : nums[i] * dp[i-1][0] ;
*/

TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{2, 3, -2, 4};
  EXPECT_EQ(s.maxProduct(nums), 6);
}
