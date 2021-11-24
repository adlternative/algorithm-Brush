#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int lens = nums.size();
    int l = 0, r = 0;
    int sum = 0;
    int min_len = INT_MAX;
    for (;;) {
      if (r < lens && sum < target) {
        sum += nums[r];
        r++;
        if (sum >= target) {
          if (min_len > r - l) {
            min_len = r - l;
          }
        }
      } else {
        while (l <= r && sum >= target) {
          sum -= nums[l];
          l++;
          if (sum >= target) {
            if (min_len > r - l) {
              min_len = r - l;
            }
          }
        }
        if (r > lens - 1)
          break;
      }
    }
    return min_len == INT_MAX ? 0 : min_len;
  }
};

TEST(Solution, minSubArrayLen1) {
  Solution s;

  vector<int> v{2, 3, 1, 2, 4, 3};
  EXPECT_EQ(s.minSubArrayLen(7, v), 2);
  v = {1, 4, 4};
  EXPECT_EQ(s.minSubArrayLen(4, v), 1);
  v = {1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(s.minSubArrayLen(11, v), 0);
}
