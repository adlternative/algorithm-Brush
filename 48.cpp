#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/*
1.5 1.5
0 0 -> 0 3
0 1 -> 1 3
1 0 -> 0 2
1 2 -> 2 2

*/

class Solution {
public:
  int len;
  double mid;

  void rotate_point(vector<vector<int>> &matrix, int i, int j) {
    /* 中心点是 [mid,mid] */
    /* 然后 (x,y) 的旋转点就是 (y, len - x) */
    int cur = matrix[i][j];
    int curi = i;
    int curj = j;

    for (int k = 0; k < 4; k++) {
      int jj = curj;
      int ii = curi;
      int temp = matrix[jj][len - 1 - ii];
      matrix[jj][len - 1 - ii] = cur;

      cur = temp;
      curi = jj;
      curj = len - 1 - ii;
    }
  }

  void rotate(vector<vector<int>> &matrix) {
    len = matrix.size();
    mid = len / 2;
    /* 中心点是 [mid,mid] */
    /* 然后 (x,y) 的旋转点就是 (y, len - x) */
    for (int i = 0; i < mid; i++) {
      for (int j = 0; j < mid; j++) {
        rotate_point(matrix, i, j);
      }
    }
    /* 奇数 */
    if (len % 2)
      for (int i = 0; i < mid; i++)
        rotate_point(matrix, i, (int)mid);
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> vv{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> result{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  s.rotate(vv);

  // for (int i = 0; i < vv.size(); i++) {
  //   for (int j = 0; j < vv[i].size(); j++) {
  //     printf("%d ", vv[i][j]);
  //   }
  //   printf("\n");
  // }

  for (int i = 0; i < vv.size(); i++) {
    for (int j = 0; j < vv[i].size(); j++) {
      EXPECT_EQ(result[i][j], vv[i][j]);
    }
  }
}

TEST(Solution, isMatch2) {
  Solution s;
  // [5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]
  vector<vector<int>> vv{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  /* [15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11] */
  vector<vector<int>> result{
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
  s.rotate(vv);

  // for (int i = 0; i < vv.size(); i++) {
  //   for (int j = 0; j < vv[i].size(); j++) {
  //     printf("%d ", vv[i][j]);
  //   }
  //   printf("\n");
  // }

  for (int i = 0; i < vv.size(); i++) {
    for (int j = 0; j < vv[i].size(); j++) {
      EXPECT_EQ(result[i][j], vv[i][j]);
    }
  }
}
