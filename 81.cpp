#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    auto lens = nums.size();
    int left = 0, right = lens - 1;
    /* 搜索最小值 */
    if (target == nums[0])
      return true;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      int mid_value = nums[mid];
      if (mid_value == target)
        return true;
      if (mid_value > nums[0]) {
        if (target > mid_value) {
          left = mid + 1;
        } else if (target < mid_value && target > nums[0]) {
          right = mid - 1;
        } else if (target < nums[0]) {
          left = mid + 1;
        }
      } else if (mid_value < nums[0]) {
        if (target < mid_value) {
          right = mid - 1;
        } else if (target > mid_value && target < nums[0]) {
          left = mid + 1;
        } else if (target > nums[0]) {
          right = mid - 1;
        }
      } else {
        /* 退化为遍历 */
        for (auto i = 0; i < lens; i++) {
          if (target == nums[i]) {
            return true;
          }
        }
        return false;
      }
    }
    return false;
  }
};

TEST(Solution, isMatch1) {
  Solution s;
  vector<int> v{2, 5, 6, 0, 0, 1, 2};
  EXPECT_EQ(s.search(v, 0), true);
  EXPECT_EQ(s.search(v, 3), false);
  EXPECT_EQ(s.search(v, 2), true);
  EXPECT_EQ(s.search(v, 6), true);
  EXPECT_EQ(s.search(v, 7), false);
  EXPECT_EQ(s.search(v, 10), false);
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> v{1, 0, 1, 1, 1};
  EXPECT_EQ(s.search(v, 0), true);
  EXPECT_EQ(s.search(v, 1), true);
  EXPECT_EQ(s.search(v, 2), false);
  EXPECT_EQ(s.search(v, 3), false);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<int> v{1, 2, 2, 2, 0, 1, 1};
  EXPECT_EQ(s.search(v, 0), true);
  EXPECT_EQ(s.search(v, 1), true);
  EXPECT_EQ(s.search(v, 2), true);
  EXPECT_EQ(s.search(v, 3), false);
}
