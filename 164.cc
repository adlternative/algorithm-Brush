#include <algorithm>
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/* 基数排序 */

class Solution {
public:
  int getN(int num, int exp) {
    int d = 1;
    for (int i = 0; i < exp; i++) {
      d *= 10;
    }
    return (num / d) % 10;
  }

  int getExp(int num) {
    int exp = 0;
    while (num) {
      num /= 10;
      exp++;
    }
    return exp;
  }
  int maximumGap(vector<int> &nums) {
    int lens = nums.size();
    vector<int> v[10];
    int max_value = *max_element(nums.begin(), nums.end());
    int max_exp = getExp(max_value);
    for (int exp = 0; exp < max_exp; exp++) {
      for (int i = 0; i < lens; i++) {
        auto n = getN(nums[i], exp);
        v[n].push_back(nums[i]); /* i? */
      }
      int c = 0;
      for (int i = 0; i < 10; i++) {
        for (auto val : v[i])
          nums[c++] = val;
        v[i].clear();
      }
    }
    int maxGap = 0;
    for (int i = 1; i < lens; i++)
      maxGap = max(maxGap, nums[i] - nums[i - 1]);
    return maxGap;
  }
};

TEST(Solution, getN) {
  Solution s;
  EXPECT_EQ(s.getN(123, 0), 3);
  EXPECT_EQ(s.getN(123, 1), 2);
  EXPECT_EQ(s.getN(123, 2), 1);
}

TEST(Solution, getExp) {
  Solution s;
  EXPECT_EQ(s.getExp(123), 3);
  EXPECT_EQ(s.getExp(1234), 4);
  EXPECT_EQ(s.getExp(1000), 4);
}

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v;

  v = {3, 6, 9, 1};
  EXPECT_EQ(s.maximumGap(v), 3);

  v = {10};
  EXPECT_EQ(s.maximumGap(v), 0);
}
