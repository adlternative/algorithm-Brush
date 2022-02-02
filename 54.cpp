#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    int r = matrix.size();
    if (!r)
      return ret;
    int c = matrix[0].size();
    int height = 0, low = r - 1, left = 0, right = c - 1;
    // for (i)
    auto i = 0, j = 0;

    while (true) {
      /* 从左向右 */
      while (j <= right) {
        ret.push_back(matrix[height][j]);
        j++;
      }
      j--;
      height++;
      if (height > low)
        return ret;
      i = height;
      /* 从上到下 */
      while (i <= low) {
        ret.push_back(matrix[i][right]);
        i++;
      }
      i--;
      right--;
      if (right < left)
        return ret;
      j = right;
      /* 从右到左 */
      while (j >= left) {
        ret.push_back(matrix[low][j]);
        j--;
      }
      j++;
      low--;
      if (height > low)
        return ret;
      i = low;
      /* 从下到上 */
      while (i >= height) {
        ret.push_back(matrix[i][left]);
        i--;
      }
      i++;
      left++;
      if (right < left)
        return ret;
      j = left;
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> matrices = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> expect{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

  auto result = s.spiralOrder(matrices);
  ASSERT_EQ(result.size(), expect.size());
  for (int i = 0; i < result.size(); i++) {
    // std::cout << result[i] << std::endl;
    EXPECT_EQ(expect[i], result[i]);
  }
}
