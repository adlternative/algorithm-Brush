#include "disjointSet.hpp"
#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

/* 思路:遍历所有的节点如果是O,则寻找它的"祖先"节点,
如果一个节点的祖先节点和一个边界节点的祖先是相同的,
则不需要填充成X,而剩下那些O则需要.
 */
using namespace index_version;
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int raw = board.size();
    if (!raw)
      return;
    int col = board[0].size();
    if (!col)
      return;
    /* 加一给虚拟节点 */
    disjointSet djs(raw * col + 1);
    for (int i = 0; i < raw; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 'O') {
          /* 边境 的节点 */
          if (i == 0 || j == 0 || i == raw - 1 || j == col - 1) {
            djs.join(i * col + j, raw * col); /* 将祖先节点全为虚拟节点 */
          } else {
            /* 非边境节点 */
            /* 如果周围节点是O */
            if (board[i][j - 1] == 'O') {
              djs.join(i * col + j - 1, i * col + j);
            }
            if (board[i][j + 1] == 'O') {
              djs.join(i * col + j + 1, i * col + j);
            }
            if (board[i - 1][j] == 'O') {
              djs.join((i - 1) * col + j, i * col + j);
            }
            if (board[i + 1][j] == 'O') {
              djs.join((i + 1) * col + j, i * col + j);
            }
          }
        }
      }
    }
    for (int i = 0; i < raw; i++) {
      for (int j = 0; j < col; j++) {
        if (i && j && i != raw - 1 && j != col - 1) {
          if (!djs.isConnected(i * col + j, raw * col)) {
            board[i][j] = 'X';
          }
        }
      }
    }
    // djs.debug();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> vv;
  // [
  //   [ "X", "X", "X", "X" ], [ "X", "O", "O", "X" ], [ "X", "X", "O", "X" ],
  //   [ "X", "O", "X", "X" ]
  // ];
  vv.emplace_back(vector<char>{'X', 'X', 'X', 'X'});
  vv.emplace_back(vector<char>{'X', 'O', 'O', 'X'});
  vv.emplace_back(vector<char>{'X', 'X', 'O', 'X'});
  vv.emplace_back(vector<char>{'X', 'O', 'X', 'X'});

  s.solve(vv);
  for (auto &&i : vv) {
    for (auto &&j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
