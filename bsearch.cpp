
#include <bits/stdc++.h>
#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int lower_bound(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  int search_first(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (left >= 0 && left < v.size() && target == v[left]) {
      return left;
    }
    return -1;
  }

  int upper_bound(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }

  int search_last(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (right >= 0 && right < v.size() - 1 && v[right] == target) {
      return right;
    }
    return -1;
  }

  bool search_insert(vector<int> &v, int target) {
    return upper_bound(v, target);
  }
};

TEST(Solution, lower_bound) {
  Solution s;
  vector<int> v{1, 2, 4, 5, 6};

  EXPECT_EQ(s.lower_bound(v, 1), 0);
  EXPECT_EQ(s.lower_bound(v, 2), 1);
  EXPECT_EQ(s.lower_bound(v, 3), 2);
  EXPECT_EQ(s.lower_bound(v, 4), 2);
  EXPECT_EQ(s.lower_bound(v, 5), 3);
  EXPECT_EQ(s.lower_bound(v, 6), 4);
  EXPECT_EQ(s.lower_bound(v, 7), 5);

  v = {1, 1, 4, 5, 6, 6};
  EXPECT_EQ(s.lower_bound(v, 1), 0);
  EXPECT_EQ(s.lower_bound(v, 2), 2);
  EXPECT_EQ(s.lower_bound(v, 4), 2);
  EXPECT_EQ(s.lower_bound(v, 5), 3);
  EXPECT_EQ(s.lower_bound(v, 6), 4);
  EXPECT_EQ(s.lower_bound(v, 7), 6);
}

TEST(Solution, upper_bound) {
  Solution s;
  vector<int> v = {1, 1, 4, 5, 6, 6};

  EXPECT_EQ(s.upper_bound(v, 1), 1);
  EXPECT_EQ(s.upper_bound(v, 2), 1);
  EXPECT_EQ(s.upper_bound(v, 3), 1);
  EXPECT_EQ(s.upper_bound(v, 4), 2);
  EXPECT_EQ(s.upper_bound(v, 5), 3);
  EXPECT_EQ(s.upper_bound(v, 6), 5);
  EXPECT_EQ(s.upper_bound(v, 7), 5);
}
