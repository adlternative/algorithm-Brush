#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    /* dp: 到 index 为止的最长升序长度
      cnt 到 index 为止的最长升序长度的不同种类数量
    */
    vector<int> dp(n), cnt(n);
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      cnt[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          /* 如果是一个新的最长升序长度  */
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            cnt[i] = cnt[j];
            /* 恰好是一个最长升序长度  */
          } else if (dp[i] == dp[j] + 1) {
            cnt[i] += cnt[j];
          }
        }
      }
    }
    int max_dp = INT_MIN;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] > max_dp) {
        max_dp = dp[i];
        ret = cnt[i];
      } else if (dp[i] == max_dp) {
        ret += cnt[i];
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{1, 3, 5, 4, 7};
  EXPECT_EQ(s.findNumberOfLIS(nums), 2);
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> nums{2, 2, 2, 2, 2};
  EXPECT_EQ(s.findNumberOfLIS(nums), 5);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<int> nums{1, 2, 4, 3, 5, 4, 7, 2};
  EXPECT_EQ(s.findNumberOfLIS(nums), 3);
}
