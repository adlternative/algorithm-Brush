#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

#ifdef t1
class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int lens = nums.size();
    int min_len = INT_MAX;
    int retain = 0;
    int sum = 0;
    while (right < lens) {
      sum += nums[right];
      right++;
      if (sum >= k && min_len > right - left)
        min_len = right - left;
      if (left < right) {
        int temp_sum = sum;
        int temp_left = left;
        // int right = right;
        retain = temp_sum - nums[temp_left];
        while (temp_left < right) {
          temp_sum = retain;
          if (temp_sum >= k) {
            sum = temp_sum;
            left = temp_left + 1;
            if (min_len > right - left)
              min_len = right - left;
          }
          temp_left++;
          if (temp_left == right)
            break;
          retain = temp_sum - nums[temp_left];
        }
      }
    }
    if (sum >= k && min_len > right - left)
      min_len = right - left;

    if (left < right) {
      int temp_sum = sum;
      int temp_left = left;
      // int right = right;
      retain = temp_sum - nums[temp_left];
      while (temp_left < right) {
        temp_sum = retain;
        if (temp_sum >= k) {
          sum = temp_sum;
          left = temp_left + 1;
          if (min_len > right - left)
            min_len = right - left;
        }
        temp_left++;
        if (temp_left == right)
          break;

        retain = temp_sum - nums[temp_left];
      }
    }

    return min_len == INT_MAX ? -1 : min_len;
  }
};
#endif

#define t2
#ifdef t2

class Solution {
public:
  long long shortestSubarray(vector<int> &A, int k) {
    long long n = A.size(), res = LONG_LONG_MAX;
    vector<long long> preSum(n + 1, 0);
    for (long i = 0; i < n; ++i) {
      preSum[i + 1] = preSum[i] + A[i];
    }
    deque<long long> deq;
    for (long i = 0; i <= n; ++i) {
      while (!deq.empty() && preSum[i] <= preSum[deq.back()]) {
        deq.pop_back();
      }
      while (!deq.empty() && preSum[i] - preSum[deq.front()] >= k) {
        res = min(res, i - deq.front());
        deq.pop_front();
      }
      deq.push_back(i);
    }
    return res == LONG_LONG_MAX ? -1 : res;
  }
};

#endif

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v;
  v = {2, -1, 2};
  EXPECT_EQ(s.shortestSubarray(v, 3), 3);
  v = {1};
  EXPECT_EQ(s.shortestSubarray(v, 1), 1);
  EXPECT_EQ(s.shortestSubarray(v, 2), -1);
  v = {1, 2};
  EXPECT_EQ(s.shortestSubarray(v, 4), -1);
  v = {-1, -2, -4, 5, 87, 1, -100};
  EXPECT_EQ(s.shortestSubarray(v, 31), 1);

  v = {84, -37, 32, 40, 95, -1};
  EXPECT_EQ(s.shortestSubarray(v, 167), 3);
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> v;
  v = {-1, -2, -4, 5, 87, 1, -100};
  EXPECT_EQ(s.shortestSubarray(v, 31), 1);
}