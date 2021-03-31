#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // int findMax(const vector<int> &arr) {
  //   int maximum_value = -1;
  //   int maximum_index = -1;
  //   int search_cost = 0;
  //   int n = arr.size();
  //   for (size_t i = 0; i < n; i++) {
  //     if (maximum_value < arr[i]) {
  //       maximum_value = arr[i];
  //       maximum_index = i;
  //       search_cost = search_cost + 1;
  //     }
  //   }
  //   return maximum_index;
  // }

  /*
   * @n: 数组的长度
   * @m: 数的上限
   * @k: 开销
   * 解题思路：
      i 当前长度 j 开销 k ”当前最大值“ （注意这里没有考虑 数的上限的一维向量）
      i+1 新数的加入可能
      有+1开销的可能，dp[i][j][k] = dp[i-1][j-1][0~k-1]
      和开销不变的可能，dp[i][j][k] =dp[i-1][j][k~m]
      初始值 dp[0] =0 //长度是0
            dp[1][1] =1//长度是1,开销是1,可以有一种
            dp[1][0]=0

      return dp[n][m][k]
   */
  static constexpr int mod = 1000000007;
  int numOfArrays(int n, int m, int k) {
    long long ret = 0;
    long long dp[n + 1][k + 1][m + 1]; /* 反过来 */

    if (n == 0 || k == 0)
      return 0;

    memset(dp, 0, sizeof(dp));
    // memset(dp[1][1], 1, sizeof(dp[1][1]));
    // dp[1][1][0] = 0;
    for (int j = 1; j <= m; ++j) {
      dp[1][1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {             //当前长度
      for (int j = 1; j <= k && j <= i; j++) { //开销
        for (int h = 1; h <= m; h++) {         //上限
          dp[i][j][h] = dp[i - 1][j][h] * h;   //它自己<h
          for (int p = 1; p < h; p++)          //最大值
          {
            dp[i][j][h] += dp[i - 1][j - 1][p]; //加上那些小于它的可能
            dp[i][j][h] %= mod;
          }
          //加上那些大于它的可能
          dp[i][j][h] %= mod;
        }
      }
    }
    for (size_t i = 0; i <= m; i++) {
      ret += dp[n][k][i];
    }

    return ret % mod;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int ret = s.numOfArrays(2, 3, 1);
  std::cout << ret << std::endl;
  return 0;
}
