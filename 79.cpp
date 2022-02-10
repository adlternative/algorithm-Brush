#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

int dict[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
  int row;
  int col;

  bool dfs(vector<vector<char>> &board, int i, int j, string_view word, int k,
           vector<vector<bool>> &setmap) {
    if (k == word.size())
      return true;

    for (int p = 0; p < 4; p++) {
      auto newi = i + dict[p][0];
      auto newj = j + dict[p][1];
      if (newi >= row || newj >= col || newi < 0 || newj < 0 ||
          setmap[newi][newj] || board[newi][newj] != word[k])
        continue;
      setmap[newi][newj] = true;
      if (dfs(board, newi, newj, word, k + 1, setmap))
        return true;
      setmap[newi][newj] = false;
    }
    return false;
  }

  bool exist(vector<vector<char>> &board, string_view word) {
    row = board.size();
    col = board[0].size();
    vector<vector<bool>> setmap(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == word[0]) {
          setmap[i][j] = true;
          if (dfs(board, i, j, word, 1, setmap))
            return true;
          setmap[i][j] = false;
        }
      }
    }
    return false;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  string word = "ABCCED";

  EXPECT_EQ(s.exist(board, word), true);
}
