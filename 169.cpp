#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    int count = 1;
    int index = 0;
    for (int i = 2; i < n; i++) {
      if (nums[i] == nums[index])
        count++;
      else {
        count--;
        if (count == 0) {
          index = i;
          count++;
        }
      }
    }
    return nums[index];
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
