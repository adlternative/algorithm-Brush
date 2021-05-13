#include "disjointSet.hpp"
#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
using namespace index_version;
using namespace std;
struct direction {
  int p; /* 水平 */
  int q; /* 垂直 */
} direct[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int raw = grid.size();
    int col = grid[0].size();
    unordered_set<int> set_;
    int nexti;
    int nextj;
    auto djs = disjointSet(raw * col);
    for (int i = 0; i < raw; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '1')
          for (int k = 0; k < 4; k++) {
            nexti = i + direct[k].p;
            nextj = j + direct[k].q;
            if (nexti >= 0 && nexti < raw && nextj >= 0 && nextj < col &&
                grid[nexti][nextj] == '1')
              djs.join(i * col + j, nexti * col + nextj);
          }
      }
    }

    for (int i = 0; i < raw; i++) {
      for (int j = 0; j < col; j++) {
        if(grid[i][j]=='1')
        set_.insert(djs.findAncestor(i * col + j));
      }
    }
    return set_.size();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> grid;
  grid.emplace_back(vector<char>{'1', '1', '0', '0', '0'});
  grid.emplace_back(vector<char>{'1', '1', '0', '0', '0'});
  grid.emplace_back(vector<char>{'0', '0', '1', '0', '0'});
  grid.emplace_back(vector<char>{'0', '0', '0', '1', '1'});
  auto ret = s.numIslands(grid);
  std::cout << ret << std::endl;
  return 0;
}
