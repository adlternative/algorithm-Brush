#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  vector<int> getMaxMatrix(vector<vector<int>> &matrix) {
    vector<int> ret(4, 0);
    int row = matrix.size();
    int col = matrix[0].size();
    int cur[col];
    int max = INT_MIN, sum = INT_MIN;
    int begin_row, begin_col;

    /* 上行 */
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++)
        cur[j] = 0;
      /* 下行 */
      for (int j = i; j < row; j++) {
        sum = 0;
        /* 每一列 */
        for (int k = 0; k < col; k++) {
          /* 一格一格加  cur[k] 已经累计了 matrix[j][0,k]*/
          cur[k] += matrix[j][k];
          /* 计算矩阵总和 */
          if (sum > 0) {
            /* 之前 sum 0 则加 cur */
            sum += cur[k];
          } else {
            /* 否则重新构造矩阵 b_r = i ,b_c = k */
            sum = cur[k];
            begin_row = i;
            begin_col = k;
          }
          /* 更新 max */
          if (sum > max) {
            max = sum;
            ret[0] = begin_row;
            ret[1] = begin_col;
            ret[2] = j;
            ret[3] = k;
          }
        }
      }
    }
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> matrix = {{-1, 0}, {-1, 0}};
  auto ret = s.getMaxMatrix(matrix);
  for (auto i : ret) {
    std::cout << i << std::endl;
  }
  return 0;
}
