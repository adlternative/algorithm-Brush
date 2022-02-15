#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int lens = nums.size();
    int max_val = target / 3 + 1;

    int closest_sum;
    int smallest_diff = INT_MAX;

    for (int i = 0; i < lens - 2 && nums[i] < max_val; i++) {
      for (int j = i + 1; j < lens - 1; j++) {
        int sum = nums[i] + nums[j];
        int diff = target - sum;

        /* find diff */
        int l = j + 1, r = lens - 1;
        while (l < r) {
          int mid = ((r - l) >> 1) + l;
          if (nums[mid] > diff) {
            r--;
          } else if (nums[mid] < diff) {
            l++;
          } else {
            return target;
          }
        }

        /* l == r  1. l diff  2. diff l */
        if (nums[l] < diff && l + 1 < lens &&
            abs(nums[l + 1] - diff) < abs(nums[l] - diff))
          l++;
        else if (nums[l] > diff && l - 1 > j &&
                 abs(nums[l - 1] - diff) < abs(nums[l] - diff))
          l--;

        diff -= nums[l];
        if (abs(diff) < smallest_diff) {
          sum += nums[l];
          closest_sum = sum;
          smallest_diff = abs(diff);
        }
      }
    }

    if (smallest_diff == INT_MAX) {
      closest_sum = nums[0] + nums[1] + nums[2];
    }

    return closest_sum;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{-1, 2, 1, -4};
  EXPECT_EQ(s.threeSumClosest(v, 1), 2);
}
TEST(Solution, isMatch2) {
  Solution s;
  vector<int> v{0, 0, 0};
  EXPECT_EQ(s.threeSumClosest(v, 1), 0);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<int> v{0, 2, 1, -3};
  EXPECT_EQ(s.threeSumClosest(v, 1), 1);
}