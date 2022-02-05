#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  void max_heapify(vector<int> &nums, int start, int end) {
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end) {
      /* 找到更大的子节点 */
      if (son + 1 <= end && nums[son] < nums[son + 1])
        son++;
      if (nums[dad] > nums[son]) {
        /* 父节点已经比两个子节点大了 */
        return;
      }
      /* 将大的子节点换到父节点上 */
      swap(nums[dad], nums[son]);
      /* 并继续向下延伸到叶节点
    （重新平衡之前已经平衡的但由于交换可能打破大堆顶规则的子树） */
      dad = son;
      son = dad * 2 + 1;
    }
  }

  /* 堆排序 */
  void heap_sort(vector<int> &nums) {
    /* 首先从最后一个父节点到第一个父节点进行调整
    （初始化一个最大堆）*/
    int len = nums.size();
    /* 完美二叉树最后一个父节点的坐标是 len/2 +1 从下向上构建大堆顶*/
    for (auto i = len / 2 - 1; i >= 0; --i) {
      max_heapify(nums, i, len - 1);
    }

    /* 通过每次交换顶部元素和最后元素，
    然后再平衡大堆顶的方式逐渐从大到小放置元素 */
    for (auto i = len - 1; i > 0; --i) {
      /* nums[0] root 节点也就是nums[0:i+1]最大值
      放到坐标为 i 的位置 */
      swap(nums[0], nums[i]);
      max_heapify(nums, 0, i - 1);
    }
  }

  vector<int> sortArray(vector<int> &nums) {
    heap_sort(nums);
    return nums;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
