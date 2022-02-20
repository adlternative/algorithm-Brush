#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int row = matrix.size();
    int col = matrix[0].size();
    int max_value = INT_MIN;
    for (int l = 0; l < row; l++) {
      for (int h = l; h < row; h++) {
        int prefixSum[col + 1];
        prefixSum[0] = 0;
        for (int i = 1; i < col; i++) {
          prefixSum[i] = prefixSum[i - 1];
          for (int j = l; j <= h; j++) {
            prefixSum[i] += matrix[j][i];
          }
        }

        for (int i = 0; i < col; i++) {
          for (int j = i + 1; j < col + 1; j++) {
            int diff = prefixSum[j] - prefixSum[i];
            if (diff <= k && diff > max_value) {
              max_value = diff;
            }
          }
        }
      }
    }
    return max_value;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
