#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
class Solution {
public:
  // struct Pointer {
  //   int x;
  //   int y;
  //   int maxLen = -1;
  // };
  struct direction {
    int p; /* 水平 */
    int q; /* 垂直 */
  } direct[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int **mem;
  int row;
  int col;
  vector<vector<int>> *matrix_;

  int dfs(int i, int j) {
    for (size_t k = 0; k < 4; k++) {
      direction &d = direct[k];
      if (0 <= (i + d.p) && (i + d.p) < row && 0 <= (j + d.q) &&
          (j + d.q) < col && (*matrix_)[i][j] < (*matrix_)[i + d.p][j + d.q]) {
        if (mem[i + d.p][j + d.q] != 0) {
          if (mem[i + d.p][j + d.q] + 1 > mem[i][j])
            mem[i][j] = mem[i + d.p][j + d.q] + 1;
        } else {
          int ret2 = dfs(i + d.p, j + d.q);
          if (ret2 + 1 > mem[i][j])
            mem[i][j] = 1 + ret2;
        }
      } else {
        /* 说明无路可走了 继续别的方向 continue */ continue;
      }
    }
    /* 四个方向都遍历完了以后，我们将mem中的更新到ret */
    return mem[i][j];
  }
  int longestIncreasingPath(vector<vector<int>> &matrix) {

    int ret = 0;
    matrix_ = &matrix;
    row = matrix.size();
    col = matrix[0].size();
    // Pointer pt[row * col];
    mem = new int *[row];
    for (size_t i = 0; i < row; i++) {
      mem[i] = new int[col];
      memset(mem[i], 0, sizeof(int) * col);
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (!mem[i][j])
          dfs(i, j);
        if (ret <= mem[i][j])
          ret = mem[i][j];
      }
    }
    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < col; j++) {
    //     cout << mem[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    for (size_t i = 0; i < row; i++) {
      delete[] mem[i];
    }
    delete[] mem;

    return ret + 1;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> vv;
  vv.emplace_back(vector<int>{9, 9, 4});
  vv.emplace_back(vector<int>{6, 6, 8});
  vv.emplace_back(vector<int>{2, 1, 1});
  auto ret = s.longestIncreasingPath(vv);
  std::cout << ret << std::endl;
  return 0;
}
