#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int c0 = 0, c1 = 0, c2 = 0;
    auto size = nums.size();
    for (int i = 0; i < size; i++) {
      switch (nums[i]) {
      case 0:
        c0++;
        break;
      case 1:
        c1++;
        break;
      case 2:
        c2++;
        break;
      }
    }
    int cur = 0;
    while (c0--) {
      nums[cur++] = 0;
    }
    while (c1--) {
      nums[cur++] = 1;
    }
    while (c2--) {
      nums[cur++] = 2;
    }
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{2, 0, 2, 1, 1, 0};
  s.sortColors(v);
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  // EXPECT_EQ(s.(), );
}
