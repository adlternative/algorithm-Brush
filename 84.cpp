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
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{4, 2, 0, 3, 2, 5};
  auto ret = s.largestRectangleArea(v);
  cout << ret << endl;
  return 0;
}
