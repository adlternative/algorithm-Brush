#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Heap {};

class Solution {
public:
  void make_heap(vector<pair<int, int>> &nums, int beg, int end) {
    while (1) {
      int son = beg * 2 + 1;
      if (son > end)
        break;

      if (son + 1 <= end && nums[son + 1].first > nums[son].first)
        son++;

      if (nums[beg].first >= nums[son].first)
        break;

      swap(nums[beg], nums[son]);
      beg = son;
    }
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> num2cnt;
    vector<int> ret;
    vector<pair<int, int>> cnt2num;

    int len1 = nums.size();
    for (int i = 0; i < len1; ++i) {
      num2cnt[nums[i]]++;
    }
    for (auto &[num, cnt] : num2cnt)
      cnt2num.emplace_back(cnt, num);

    int lens = cnt2num.size();
    for (int i = lens / 2 + 1; i >= 0; --i)
      make_heap(cnt2num, i, lens - 1);
    for (int i = 0; i < k; i++) {
      swap(cnt2num[0], cnt2num[lens - i - 1]);
      ret.push_back(cnt2num[lens - i - 1].second);
      make_heap(cnt2num, 0, lens - i - 2);
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;

  vector<int> nums{1, 2};
  vector<int> v = s.topKFrequent(nums, 2);
  for (auto i : v) {
    std::cout << i << std::endl;
  }
}
