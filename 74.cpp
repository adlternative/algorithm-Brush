#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    int lens = r * c;
    int left = 0, right = lens - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int val = matrix[mid / c][mid % c];
      if (val < target) {
        left = mid + 1;
      } else if (val > target) {
        right = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> vv{
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60},
  };
  EXPECT_EQ(s.searchMatrix(vv, 0), false);
  EXPECT_EQ(s.searchMatrix(vv, 1), true);
  EXPECT_EQ(s.searchMatrix(vv, 3), true);
  EXPECT_EQ(s.searchMatrix(vv, 11), true);
  EXPECT_EQ(s.searchMatrix(vv, 13), false);
  EXPECT_EQ(s.searchMatrix(vv, 34), true);
  EXPECT_EQ(s.searchMatrix(vv, 60), true);
  EXPECT_EQ(s.searchMatrix(vv, 61), false);
}
