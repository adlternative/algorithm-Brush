
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

  int search_insert(vector<int> &v, int target) {
    return upper_bound(v, target);
  }

  int search_test(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left < right) {
      int mid = left + ((right - left) >> 1);

      if (v[mid] < target) {
        left = mid + 1;
      } else if (v[mid] > target) {
        right = mid;
      } else {
        return mid;
      }
    }
    return left;
  }

  int search_test2(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] < target) {
        left = mid + 1;
      } else if (v[mid] > target) {
        right = mid;
      } else {
        return mid;
      }
    }
    return v[left] == target ? left : -1;
  }

  int search_no_greater_than(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;

    /* 寻找恰好比要求的值小的那个位置 */
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (v[mid] < target) {
        /* 目标大，则 left++ */
        left = mid + 1;
      } else {
        /* 目标小或者相等，则 right-- */
        right = mid - 1;
      }
    }

    /* 最终 right == left - 1  */
    if (left != v.size() && v[left] == target) {
      return left;
    } else {
      return right;
    }
  }
};

TEST(Solution, search_no_greater_than) {
  Solution s;
  vector<int> v{1, 2, 4, 5, 6};

  EXPECT_EQ(s.search_no_greater_than(v, 0), -1);
  EXPECT_EQ(s.search_no_greater_than(v, 1), 0);
  EXPECT_EQ(s.search_no_greater_than(v, 2), 1);
  EXPECT_EQ(s.search_no_greater_than(v, 3), 1);
  EXPECT_EQ(s.search_no_greater_than(v, 4), 2);
  EXPECT_EQ(s.search_no_greater_than(v, 5), 3);
  EXPECT_EQ(s.search_no_greater_than(v, 6), 4);
  EXPECT_EQ(s.search_no_greater_than(v, 7), 4);

  v = {1, 1, 4, 5, 6, 6};
  EXPECT_EQ(s.search_no_greater_than(v, 0), -1);
  EXPECT_EQ(s.search_no_greater_than(v, 1), 0);
  EXPECT_EQ(s.search_no_greater_than(v, 2), 1);
  EXPECT_EQ(s.search_no_greater_than(v, 4), 2);
  EXPECT_EQ(s.search_no_greater_than(v, 5), 3);
  EXPECT_EQ(s.search_no_greater_than(v, 6), 4);
  EXPECT_EQ(s.search_no_greater_than(v, 7), 5);
}

TEST(Solution, search_test) {
  Solution s;
  vector<int> v{1, 2, 4, 5, 6};

  EXPECT_EQ(s.search_test(v, 0), 0);
  EXPECT_EQ(s.search_test(v, 1), 0);
  EXPECT_EQ(s.search_test(v, 2), 1);
  EXPECT_EQ(s.search_test(v, 3), 2);
  EXPECT_EQ(s.search_test(v, 4), 2);
  EXPECT_EQ(s.search_test(v, 5), 3);
  EXPECT_EQ(s.search_test(v, 6), 4);
  EXPECT_EQ(s.search_test(v, 7), 4);

  v = {1, 1, 4, 5, 6, 6};
  EXPECT_EQ(s.search_test(v, 0), 0);
  EXPECT_EQ(s.search_test(v, 1),
            1); /* 其实这里是选择任意一个返回，所以 0 1 都可以 */
  EXPECT_EQ(s.search_test(v, 2), 2);
  EXPECT_EQ(s.search_test(v, 4), 2);
  EXPECT_EQ(s.search_test(v, 5), 3);
  EXPECT_EQ(s.search_test(v, 6), 4);
  EXPECT_EQ(s.search_test(v, 7), 5);
}

TEST(Solution, search_test2) {
  Solution s;
  vector<int> v{1, 2, 4, 5, 6};

  EXPECT_EQ(s.search_test2(v, 0), -1);
  EXPECT_EQ(s.search_test2(v, 1), 0);
  EXPECT_EQ(s.search_test2(v, 2), 1);
  EXPECT_EQ(s.search_test2(v, 3), -1);
  EXPECT_EQ(s.search_test2(v, 4), 2);
  EXPECT_EQ(s.search_test2(v, 5), 3);
  EXPECT_EQ(s.search_test2(v, 6), 4);
  EXPECT_EQ(s.search_test2(v, 7), -1);

  v = {1, 1, 4, 5, 6, 6};
  EXPECT_EQ(s.search_test2(v, 0), -1);
  EXPECT_EQ(s.search_test2(v, 1), 1);
  EXPECT_EQ(s.search_test2(v, 2), -1);
  EXPECT_EQ(s.search_test2(v, 4), 2);
  EXPECT_EQ(s.search_test2(v, 5), 3);
  EXPECT_EQ(s.search_test2(v, 6), 4);
  EXPECT_EQ(s.search_test2(v, 7), -1);
}

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
  EXPECT_EQ(s.lower_bound(v, 0), 0);
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
