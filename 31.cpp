#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    /* 1. 从右向左寻找乱序数 */
    int lens = nums.size();
    int cur = lens - 1;
    while (cur && nums[cur] <= nums[cur - 1]) {
      --cur;
    }
    if (!cur) {
      reverse(nums.begin(), nums.end());
      return;
    }
    --cur;
    /* 在 cur + 1 ~ end 之间寻找最右边第一个大于
      nums[cur] 的数字进行交换 */
    int l = cur + 1, r = lens - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] > nums[cur]) {
        l++;
      } else {
        r--;
      }
    }
    swap(nums[r], nums[cur]);
    sort(nums.begin() + cur + 1, nums.end());
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector v{1, 2, 3};
  vector expect{1, 3, 2};
  s.nextPermutation(v);
  int lens = v.size();
  for (int i = 0; i < lens; i++) {
    EXPECT_EQ(v[i], expect[i]);
  }
  v = {3, 2, 1};
  expect = {1, 2, 3};
  s.nextPermutation(v);
  for (int i = 0; i < lens; i++) {
    EXPECT_EQ(v[i], expect[i]);
  }
}
