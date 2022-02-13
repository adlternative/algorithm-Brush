#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maxArea(vector<int> &height) {
    int ret = 0;
    int lens = height.size();
    if (lens <= 1)
      return ret;
    int left = 0, right = lens - 1;
    while (left < right) {
      ret = max(ret, (right - left) * min(height[left], height[right]));
      if (height[left] > height[right])
        right--;
      else
        left++;
    }
    return ret;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(s.maxArea(v), 49);
}
