#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    /* [00] -> [01 -> 10] -> [20 11 02] -> ... ->  */
    vector<int> ret;
    int row = mat.size();
    int col = mat[0].size();
    for (int i = 0; i <= row + col - 2; i++) {
      if (i % 2) {
        /* 从 右边向左 [0x] -> [x0] */
        int v = min(i, row - 1);
        for (int j = max(0, i - col + 1); j <= v; j++)
          ret.push_back(mat[j][i - j]);
      } else {
        /* 从 左边向右 [x0] -> [0x] */
        int v = min(i, col - 1);
        for (int j = max(0, i - row + 1); j <= v; j++)
          ret.push_back(mat[i - j][j]);
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> expect{1, 2, 4, 7, 5, 3, 6, 8, 9};
  auto result = s.findDiagonalOrder(vv);

  for (auto i = 0; i < result.size(); i++)
    EXPECT_EQ(result[i], expect[i]);
}
