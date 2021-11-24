#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lg                  test -lgtest_main */

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    auto lens = nums.size();
    int l = 0, r = lens - 1;
    if (lens == 1)
      return l;
    if (nums[l] > nums[l + 1]) {
      return l;
    } else if (nums[r] > nums[r - 1]) {
      return r;
    }

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (mid == 0)
        l++;
      else if (mid == lens - 1)
        r--;
      else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid] < nums[mid - 1]) {
        r = mid - 1;
      } else if (nums[mid] < nums[mid + 1]) {
        l = mid + 1;
      }
    }
    return -1;
  }
};

TEST(Solution, findPeakElement) {
  Solution s;
  vector<int> v{3, 4, 3, 2, 1};
  EXPECT_EQ(s.findPeakElement(v), 1);
}
