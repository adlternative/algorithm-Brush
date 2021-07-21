#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int maxArea = 0;
    int len = heights.size();
    vector<int> stk;
    auto i = 0;

    stk.push_back(i++);

    for (; i != len; i++) {
      while (i != len && heights[stk.back()] <= heights[i]) {
        stk.push_back(i++);
      }
      if (i == len)
        break;

      /* 说明不单调递增了 */
      while (stk.size() && heights[stk.back()] > heights[i]) {
        maxArea = max(
            maxArea, heights[stk.back()] *
                         (i - (stk.size() == 1 ? 0 : stk[stk.size() - 2] + 1)));
        stk.pop_back();
      }
      stk.push_back(i);
    }

    while (stk.size() && heights[stk.back()] >= 0) {
      maxArea = max(maxArea,
                    heights[stk.back()] *
                        (i - (stk.size() == 1 ? 0 : stk[stk.size() - 2] + 1)));
      stk.pop_back();
    }
    return maxArea;
  }

  int maximalRectangle(vector<vector<char>> &matrix) {
    int ret = 0;

    int raw = matrix.size();
    if (raw == 0)
      return 0;

    int col = matrix[0].size();
    if (col == 0)
      return 0;

    vector<int> heights(matrix[0].size(), 0);

    for (int i = 0; i != raw; i++) {
      for (int j = 0; j != col; j++) {
        heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
      }
      ret = max(ret, largestRectangleArea(heights));
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> vv;
  vv.emplace_back(vector<char>{'1', '0', '1', '0', '0'});
  vv.emplace_back(vector<char>{'1', '0', '1', '1', '1'});
  vv.emplace_back(vector<char>{'1', '1', '1', '1', '1'});
  vv.emplace_back(vector<char>{'1', '0', '0', '1', '0'});
  auto ret = s.maximalRectangle(vv);
  std::cout << ret << std::endl;
  return 0;
}
