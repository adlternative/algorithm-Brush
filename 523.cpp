#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> premod2idx;
    int lens = nums.size();
    int prefix_sum = 0;
    premod2idx.emplace(0, -1);
    for (int i = 0; i < lens; i++) {
      prefix_sum += nums[i];
      int mod_val = prefix_sum % k;
      auto iter = premod2idx.find(mod_val);
      if (iter != premod2idx.end()) {
        if (i - iter->second >= 2)
          return true;
      } else {
        premod2idx.emplace(mod_val, i);
      }
    }
    return false;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{23, 2, 4, 6, 7};
  EXPECT_EQ(s.checkSubarraySum(nums, 6), true);
}
