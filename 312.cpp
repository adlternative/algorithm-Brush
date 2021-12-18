#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int lens = (int)nums.size();
    vector<vector<int>> dp(lens + 2, vector<int>(lens + 2, INT_MIN));
    /* i j 均为开区间 */
    /* 边界 i j 0 , len + 1 */
    /* 数据位于 1 ，len */
    for (int i = lens + 1; i >= 0; i--) {
      for (int j = 0; j <= lens + 1; j++) {
        if (i + 1 >= j) {
          dp[i][j] = 0;
        } else {
          /* i = 0 j = len +1 时 k 属于 1 到 len */
          for (int k = i + 1; k <= j - 1; k++) {
            int v1, v2;

            if (i == 0 && j == lens + 1) {
              v1 = 1;
              v2 = 1;
            } else if (i == 0) {
              v1 = 1;
              v2 = nums[j - 1];
            } else if (j == lens + 1) {
              v1 = nums[i - 1];
              v2 = 1;
            } else {
              v1 = nums[i - 1];
              v2 = nums[j - 1];
            }
            dp[i][j] =
                max(dp[i][j], v1 * nums[k - 1] * v2 + dp[i][k] + dp[k][j]);
          }
        }
      }
    }
    // for (int i = 0; i <= lens + 1; i++) {
    //   for (int j = 0; j <= lens + 1; j++) {
    //     std::cout << dp[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    // std::cout << std::endl;

    return dp[0][lens + 1];
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{3, 1, 5, 8};
  EXPECT_EQ(s.maxCoins(v), 167);
}
