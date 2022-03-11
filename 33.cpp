#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int bsearch(vector<int> &nums, int begin, int end, int target, bool direct) {
    int b = begin;
    int e = end;
    while (b < e) {
      int mid = (b + e) >> 1;
      if (nums[mid] > target) {
        e--;
      } else if (nums[mid] < target) {
        b++;
      } else {
        return true;
      }
    }
    return -1;
  }

  int search(vector<int> &nums, int target) {
    int lens = nums.size();
    if (lens == 1)
      return nums[0] == target;
    else if (lens == 2)
      return nums[0] == target || nums[1] == target;

    if (nums[0] < nums[lens - 1]) {
      /* 整体有序 直接 bsearch */
      return bsearch(nums, 0, lens - 1, target, true);
    }

    int b = 0, e = lens - 1;
    int mid;
    /* 寻找 max */
    while (b < e) {
      mid = (b + e) >> 1;
      if (nums[mid] > nums[mid + 1])
        break;

      if (nums[mid] > nums[b])
        b = mid;
      else if (nums[mid] < nums[e]) {
        e = mid - 1;
      }
    }
    while (nums[mid] < nums[mid + 1])
      mid++;

    if (target > nums[0]) {
      return bsearch(nums, 0, mid, target, true);
    } else {
      return bsearch(nums, mid + 1, lens - 1, target, false);
    }
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
