#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lens = nums.size();
    int b = 0, e = lens - 1;
    while (b <= e) {
      int mid = (b + e) >> 1;
      if (nums[mid] >= nums[0]) {
        if (nums[0] <= target && target <= nums[mid]) {
          e = mid - 1;
        } else {
          b = mid + 1;
        }
      } else if (nums[mid] <= nums[lens - 1]) {
        if (nums[lens - 1] >= target && target >= nums[mid]) {
          b = mid + 1;
        } else {
          e = mid - 1;
        }
      }
    }
    if (b >= 0 && b <= lens - 1 && nums[b] == target)
      return b;
    if (e >= 0 && e <= lens - 1 && nums[e] == target)
      return e;
    return -1;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{4, 5, 6, 7, 0, 1};
  EXPECT_EQ(s.search(v, 0), 4);
  EXPECT_EQ(s.search(v, 3), -1);
  vector<int> v2{1};
  EXPECT_EQ(s.search(v2, 0), -1);
  vector<int> v3{1,3};
  EXPECT_EQ(s.search(v3, 1), 0);
}
