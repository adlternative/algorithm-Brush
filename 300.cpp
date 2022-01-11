#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (!i || nums[i] > dp.back()) {
        dp.push_back(nums[i]);
      } else {
        int l = 0, r = dp.size() - 1;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (dp[mid] >= nums[i]) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
        if (l != dp.size())
          dp[l] = nums[i];
      }
    }
    return dp.size();
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
