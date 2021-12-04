#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

#ifdef m1

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    auto lens = nums.size();
    deque<int> tmp;
    vector<int> ret(lens, 0);
    if (!lens)
      return ret;
    /* 最后一个数字 */
    tmp.push_back(nums[lens - 1]);
    ret[lens - 1] = 0;
    /* 从右向左所有数字 */
    for (int i = lens - 2; i >= 0; i--) {
      if (nums[i] <= tmp[0]) {
        /* 这个数足够小直接插入到 tmp 最前面 */
        ret[i] = 0;
        tmp.push_front(nums[i]);
      } else if (nums[i] > tmp[tmp.size() - 1]) {
        /* 这个数足够大直接插入到 tmp 最后面 */
        ret[i] = tmp.size();
        tmp.push_back(nums[i]);
      } else {
        /* 找最左边的可插入点 lower_bound */
        int left = 0;
        int right = tmp.size() - 1;
        while (left <= right) {
          int mid = (left + right) / 2;
          if (nums[i] > tmp[mid]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        tmp.insert(tmp.begin() + left, nums[i]);
        ret[i] = left;
      }
    }
    return ret;
  }
};
#endif

#ifdef bug_m2

class Solution {
public:
  void merge_sort(vector<int> &nums, vector<int> &ret, int begin, int end) {
    if (begin + 1 >= end)
      return;
    /* [begin , (begin + end) / 2 - 1] 局部有序 */
    merge_sort(nums, ret, begin, (end + begin) / 2);
    /* [(begin + end) / 2 , end - 1] 局部有序 */
    merge_sort(nums, ret, (end + begin) / 2, end);
    /* 对两个范围进行合并 */

    vector<int> tmp(end - begin, 0);
    vector<int> tmp_index(end - begin);

    for (int i = 0; i < end - begin; i++) {
      tmp_index[i] = index[begin + i];
    }

    int i = begin, j = (end + begin) / 2;
    int cur = 0;

    for (; i != (end + begin) / 2 && j != end;) {
      if (nums[i] < nums[j]) {
        /* 右大,看左超过多少右 */
        ret[index[i]] += j - (end + begin) / 2;
        /* 新坐标 */
        tmp_index[cur] = index[i];
        tmp[cur++] = nums[i++];
      } else if (nums[i] > nums[j]) {
        /* 左大 */
        tmp_index[cur] = index[j];
        tmp[cur++] = nums[j++];
      } else {
        tmp_index[cur] = index[i];
        tmp[cur++] = nums[i++];
        tmp_index[cur] = index[j];
        tmp[cur++] = nums[j++];
      }
    }
    if (i == (end + begin) / 2) {
      for (; j != end;) {
        tmp_index[cur] = index[j];
        tmp[cur++] = nums[j++];
      }
    } else {
      for (; i != (end + begin) / 2;) {
        ret[index[i]] += j - (end + begin) / 2;
        tmp_index[cur] = index[i];
        tmp[cur++] = nums[i++];
      }
    }
    /* copy tmp -> nums[begin,end] */
    for (int i = 0; i < tmp.size(); i++, begin++) {
      nums[begin] = tmp[i];
      index[begin] = tmp_index[i];
    }
  }

  vector<int> index;

  vector<int> countSmaller(vector<int> &nums) { /* merge sort */
    int lens = nums.size();
    vector<int> ret(lens, 0);
    index = vector<int>(lens);
    for (int i = 0; i < lens; i++)
      index[i] = i;
    merge_sort(nums, ret, 0, lens);
    return ret;
  }
};
#endif

class Solution {
public:
  using VecPair = vector<pair<int, int>>;
  using VecPairIt = vector<pair<int, int>>::iterator;
  vector<int> countSmaller(vector<int> &nums) {
    vector<pair<int, int>> v;
    int n = nums.size();
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
      v.emplace_back(nums[i], i);
    }

    vector<int> res(n);
    merge_sort(v.begin(), v.end(), res);
    return res;
  }

  void merge_sort(VecPairIt l, VecPairIt r, vector<int> &res) {
    if (r - l <= 1)
      return;
    auto mid = l + (r - l) / 2;
    merge_sort(l, mid, res); // [l, mid)
    merge_sort(mid, r, res); // [mid, r)

    auto i = l;
    auto j = mid;
    while (i < mid || j < r) {
      if (j == r || (i < mid && i->first <= j->first)) {
        res[i->second] += j - mid;
        ++i;
      } else {
        ++j;
      }
    }

    inplace_merge(l, mid, r);
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> nums = {5, 2, 6, 1};
  auto ret = s.countSmaller(nums);
  EXPECT_EQ(ret.size(), 4);
  EXPECT_EQ(ret[0], 2);
  EXPECT_EQ(ret[1], 1);
  EXPECT_EQ(ret[2], 1);
  EXPECT_EQ(ret[3], 0);
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> nums = {-1};
  auto ret = s.countSmaller(nums);
  EXPECT_EQ(ret.size(), 1);
  EXPECT_EQ(ret[0], 0);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<int> nums = {-1, -1};
  auto ret = s.countSmaller(nums);
  EXPECT_EQ(ret.size(), 2);
  EXPECT_EQ(ret[0], 0);
  EXPECT_EQ(ret[1], 0);
}

TEST(Solution, isMatch4) {
  Solution s;
  vector<int> nums = {5, 4, 3, 2, 1};
  auto ret = s.countSmaller(nums);
  EXPECT_EQ(ret.size(), 5);
  EXPECT_EQ(ret[0], 4);
  EXPECT_EQ(ret[1], 3);
  EXPECT_EQ(ret[2], 2);
  EXPECT_EQ(ret[3], 1);
  EXPECT_EQ(ret[4], 0);
}

TEST(Solution, isMatch5) {
  Solution s;
  vector<int> nums = {0, 1, 2};
  auto ret = s.countSmaller(nums);
  EXPECT_EQ(ret.size(), 3);
  EXPECT_EQ(ret[0], 0);
  EXPECT_EQ(ret[1], 0);
  EXPECT_EQ(ret[2], 0);
}
TEST(Solution, isMatch6) {
  Solution s;
  vector<int> nums = {51, 9, 21, 84, 66, 65, 36, 100, 41};
  auto ret = s.countSmaller(nums);
  vector<int> expect = {4, 0, 0, 4, 3, 2, 0, 1, 0};
  EXPECT_EQ(ret.size(), 9);
  for (int i = 0; i < nums.size(); i++) {
    EXPECT_EQ(ret[i], expect[i]);
  }
}

TEST(Solution, isMatch7) {
  Solution s;
  vector<int> nums = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5,  38,  7,  35, 23,
                      52, 22, 83, 51,  98, 69, 81, 32, 78, 28, 94,  13, 2,  97,
                      3,  76, 99, 51,  9,  21, 84, 66, 65, 36, 100, 41};
  auto ret = s.countSmaller(nums);
  vector<int> expect = {10, 27, 10, 35, 12, 22, 28, 8, 19, 2, 12, 2, 9, 6,
                        12, 5,  17, 9,  19, 12, 14, 6, 12, 5, 12, 3, 0, 10,
                        0,  7,  8,  4,  0,  0,  4,  3, 2,  0, 1,  0};
  // EXPECT_EQ(ret.size(), 9);
  for (int i = 0; i < nums.size(); i++) {
    EXPECT_EQ(ret[i], expect[i]);
  }
}
