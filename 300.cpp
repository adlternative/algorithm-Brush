#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    /* 以 dp[i] 为结尾 最长长度*/
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
      ret = max(dp[i], ret);
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(s.lengthOfLIS(nums), 4);

  nums = {0, 1, 0, 3, 2, 3};
  EXPECT_EQ(s.lengthOfLIS(nums), 4);
  nums = {7, 7, 7, 7, 7, 7, 7};
  EXPECT_EQ(s.lengthOfLIS(nums), 1);
}
