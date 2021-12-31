#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int lens = nums.size();
    vector<vector<int>> ret;

    for (int i = 0; i < (1 << lens); i++) {
      vector<int> v;
      for (int j = 0; j < lens; j++) {
        if (i & (1 << j))
          v.push_back(nums[j]);
      }

      ret.push_back(std::move(v));
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums{1, 2, 3};
  auto result = s.subsets(nums);
  auto expect =
      vector<vector<int>>{{}, {1}, {2}, {1, 2}, {3}, {2, 3}, {1, 3}, {1, 2, 3}};
  for (auto &v : result) {
    printf("----\n");
    for (auto &e : v) {
      printf("%d ", e);
    }
    printf("\n");
  }
}

TEST(Solution, bit) { printf("%d\n", 1 << 3); }