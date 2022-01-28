#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int len = m + n;
    while (len && m && n) {
      int l = nums1[m - 1];
      int r = nums2[n - 1];
      if (l > r) {
        nums1[--len] = l;
        --m;
      } else {
        nums1[--len] = r;
        --n;
      }
    }
    while (n) {
      nums1[--len] = nums2[--n];
    }
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector v1{1, 2, 3, 0, 0, 0};
  vector v2{2, 5, 6};
  vector expect{1, 2, 2, 3, 5, 6};
  s.merge(v1, 3, v2, 3);
  for (int i = 0; i < expect.size(); i++) {
    EXPECT_EQ(v1[i], expect[i]);
  }
}
