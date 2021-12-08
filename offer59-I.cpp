#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/* 1, 3, -1, -3, -1, 3, 6, 7
max = 3
max = 3
max = -1


  */

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int lens = nums.size();
    vector<int> ret(lens - k + 1);

    if (!lens)
      return ret;

    priority_queue<pair<int, int>> queue;
    for (int i = 0; i < k; i++) {
      queue.emplace(nums[i], i);
    }
    ret[0] = queue.top().first;

    for (int i = k; i < lens; i++) {
      queue.emplace(nums[i], i);
      while (queue.top().second <= i - k) {
        queue.pop();
      }
      ret[i - k + 1] = queue.top().first;
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> result{3, 3, 5, 5, 6, 7};
  auto output = s.maxSlidingWindow(v, 3);
  for (auto i = 0; i < output.size(); i++) {
    EXPECT_EQ(output[i], result[i]);
  }
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> v{1, -1};
  vector<int> result{1, -1};
  auto output = s.maxSlidingWindow(v, 1);
  for (auto i = 0; i < output.size(); i++) {
    EXPECT_EQ(output[i], result[i]);
  }
}