#include <bits/stdc++.h>
// #include <fmt/format.h>
#include <gtest/gtest.h>
using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  using v2i = pair<int, int>;

  int direct[4][2] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0},
  };

  int trapRainWater(vector<vector<int>> &heightMap) {
    int ret = 0;
    int r = heightMap.size();
    int c = heightMap[0].size();
    if (r <= 2 || c <= 2)
      return ret;

    auto out_range = [&](int x, int y) -> auto {
      return x < 0 || y < 0 || x >= r || y >= c;
    };

    priority_queue<v2i, vector<v2i>, greater<v2i>> pq;
    vector<vector<bool>> visit(r, vector<bool>(c, false));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
          pq.push({heightMap[i][j], i * c + j});
          visit[i][j] = true;
        }
      }
    }

    while (pq.size()) {
      auto minNode = pq.top();
      pq.pop();
      int val = minNode.first;
      int index = minNode.second;
      int ir = index / c;
      int ic = index % c;

      for (int i = 0; i < 4; i++) {
        int nir = ir + direct[i][0];
        int nic = ic + direct[i][1];
        /* 越界或已遍历则跳过 */
        if (out_range(nir, nic) || visit[nir][nic])
          continue;
        visit[nir][nic] = true;
        pq.push({max(heightMap[nir][nic], val), nir * c + nic});
        if (heightMap[nir][nic] < val)
          ret += val - heightMap[nir][nic];
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> vv(3);
  vv[0] = {1, 4, 3, 1, 3, 2};
  vv[1] = {3, 2, 1, 3, 2, 4};
  vv[2] = {2, 3, 3, 2, 3, 1};
  EXPECT_EQ(s.trapRainWater(vv), 4);
}

/*
1, 4, 3, 1, 3, 2
3, 2, 1, 3, 2, 4
2, 3, 3, 2, 3, 1

*/