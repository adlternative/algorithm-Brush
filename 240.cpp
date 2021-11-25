#include <bits/stdc++.h>
#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int b_x = 0, b_y = 0;
    int e_x = row - 1, e_y = col - 1;

    while (b_x < e_x && b_y < e_y) {
      /* 最后一行 */
      int left = b_y;
      int right = e_y;

      while (left <= right) {
        int mid = left + ((right - left) >> 1);

        if (matrix[e_x][mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      if (left < col && matrix[e_x][left] == target) {
        return true;
      }

      // EXPECT_EQ(left, 1);
      /* 更新左界 */
      b_y = left;

      /* 最后一列 */
      left = b_x;
      right = e_x;

      while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (matrix[mid][e_y] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      if (left < row && matrix[left][e_y] == target) {
        return true;
      }

      // EXPECT_EQ(left, 2);
      b_x = left;

      e_x--;
      e_y--;
    }

    if (b_x > e_x || b_y > e_y) {
      return false;
    }

    if (b_x == e_x) {
      int left = b_y;
      int right = e_y;

      while (left <= right) {
        int mid = left + ((right - left) >> 1);

        if (matrix[e_x][mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      if (left < col && matrix[e_x][left] == target) {
        return true;
      }
    } else if (b_y == e_y) {
      int left = b_x;
      int right = e_x;

      while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (matrix[mid][e_y] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      if (left < row && matrix[left][e_y] == target) {
        return true;
      }
    }

    return false;
  }
};

TEST(Solution, searchMatrix) {
  Solution s;
  vector<vector<int>> vv = {{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}};
  EXPECT_EQ(s.searchMatrix(vv, 20), false);
  EXPECT_EQ(s.searchMatrix(vv, 21), true);
  EXPECT_EQ(s.searchMatrix(vv, 22), true);
  EXPECT_EQ(s.searchMatrix(vv, 5), true);
  EXPECT_EQ(s.searchMatrix(vv, 31), false);
  EXPECT_EQ(s.searchMatrix(vv, 0), false);
  EXPECT_EQ(s.searchMatrix(vv, 30), true);
}

TEST(Solution, searchMatrix2) {
  Solution s;
  vector<vector<int>> vv = {{1, 3, 5}};

  EXPECT_EQ(s.searchMatrix(vv, -1), false);
}
