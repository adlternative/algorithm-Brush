#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

int dict[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    auto end = n * n;
    int v = 1;
    ret[0][0] = v++;
    int x = 0, y = 0;
    int bx = 0, ex = n, by = 0, ey = n;

    int dic = 0;
    int remain;
    while (v <= end) {
      remain = dic % 4;

      if (!remain) {
        while (++y < ey) {
          ret[bx][y] = v++;
        }
        y--;
        bx++;
      } else if (remain == 1) {
        while (++x < ex) {
          ret[x][ey - 1] = v++;
        }
        x--;
        ey--;
      } else if (remain == 2) {
        while (--y >= by) {
          ret[ex - 1][y] = v++;
        }
        y++;
        ex--;
      } else {
        while (--x >= bx) {
          ret[x][by] = v++;
        }
        x++;
        by++;
      }
      dic++;
    }
    return ret;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  auto ret = s.generateMatrix(3);
  ASSERT_EQ(ret.size(), 3);
  for (size_t i = 0; i < ret.size(); i++) {
    for (size_t j = 0; j < ret[0].size(); j++) {
      std::cout << ret[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
