#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  /* 多少组 前缀和之差等于 k  */

  int subarraySum(vector<int> &nums, int k) {
    int sum = 0;
    int pre_sum;
    unordered_map<int, int> val2cnt;
    int lens = nums.size();

    val2cnt[0] = 1;

    for (int i = 0; i < lens; i++) {
      int new_pre_sum;
      if (!i) {
        new_pre_sum = nums[i];
      } else {
        new_pre_sum = pre_sum + nums[i];
      }

      pre_sum = new_pre_sum;
      sum += val2cnt[new_pre_sum - k];

      val2cnt[new_pre_sum]++;
    }
    return sum;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{1, 1, 1};
  EXPECT_EQ(s.subarraySum(nums, 2), 2);
}
