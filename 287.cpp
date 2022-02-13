#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int lens = nums.size();
    int bitmap[lens / 8 + 1];
    for (int i = 0; i < lens / 8 + 1; i++)
      bitmap[i] = 0;

    for (int i = 0; i < lens; i++) {
      int index = nums[i] / 8;
      int remain = nums[i] % 8;
      if (bitmap[index] & (1 << remain))
        return nums[i];
      bitmap[index] |= (1 << remain);
    }
    return 0;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 3, 4, 2, 2};
  EXPECT_EQ(s.findDuplicate(v), 2);
}
