#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int lens = len1 + len2;
    if (lens % 2)
      return getKth(nums1, nums2, (lens + 1) / 2);
    else
      return (double)(getKth(nums1, nums2, lens / 2) +
                      getKth(nums1, nums2, lens / 2 + 1)) /
             2.0;
  }

  int getKth(vector<int> &nums1, vector<int> &nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    // int lens = len1 + len2;
    int k0 = k;
    int cur1 = 0, cur2 = 0;
    int v1, v2;
    while (1) {
      /* 第一个数组遍历完了，从另一个数组取 */
      if (cur1 == len1) {
        return nums2[cur2 + k0 - 1];
      }
      if (cur2 == len2) {
        return nums1[cur1 + k0 - 1];
      }
      /* 如果只有最后一个，直接从两个数组当前位置取最小的那个数字
      （注意我们之前更新 cur 可能更新到数组的末尾，所以必须放在 上面俩判断下面）
    */
      if (k0 == 1) {
        return min(nums1[cur1], nums2[cur2]);
      }
      /* 取到 cur + k/2 -1 进行比较 （除非到了末尾）*/
      int next1 = min(cur1 + k0 / 2 - 1, len1 - 1);
      int next2 = min(cur2 + k0 / 2 - 1, len2 - 1);
      v1 = nums1[next1];
      v2 = nums2[next2];
      /* 排除更小的那段 */
      if (v1 <= v2) {
        k0 -= next1 - cur1 + 1;
        cur1 = next1 + 1;
      } else {
        k0 -= next2 - cur2 + 1;
        cur2 = next2 + 1;
      }
    }
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v1{1, 2};
  vector<int> v2{3, 4};
  EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
  // v1 = {1, 2, 3, 4};
  // v2 = {1, 2, 3, 4};
  // EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
  // v1 = {1, 3, 5, 6, 10, 12};
  // v2 = {7, 8, 10, 13, 15}; // 11 /2 =5
  // EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 8);
  v1 = {1};
  v2 = {7, 8, 10, 13, 15}; // 11 /2 =5
  EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 9);
}
