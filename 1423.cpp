#include <bits/stdc++.h>
using namespace std;
/*
 * 分析：我们的牌有一定数量 len,
 * 最大可以拿的数量是 k
 * 左右获得最大点数max=dp[]
 * 状态：最大的点数变化
 * 变化：拿新的一张牌从头 或者从尾
 * 是否需要记录 我们取牌的坐标？
 * dp[head][tail] = value
 * dp[head][tail] = max(dp[head-1][tail] + cardPoints[head],
 *  cardPoint[tail]+dp[head][tail+1])
 * init: dp[0][len]=0 取左 head+1 取右tail-1 head=0开始，tail=len开始，
 * 返回的是k张牌取完以后　的多个dp[head][tail]最大值?
 * 事实上，dp[0][len]在我们取完k张牌以后　特殊情况下　head=k　tail=len 或head=0
 * tail=len-k，那么结束条件是tail-head=k,然后我们将这些中的最大值找出来就好了
 *
 */

// class Solution {
// public:
//   size_t len;
//   int maxScore(vector<int> &cardPoints, int k) {
//     len = cardPoints.size();
//     long long dp[len + 2][len + 2];
//     // long long **dp = new long long *[len + 2];
//     // for (size_t i = 0; i < len + 2; i++) {
//     //   dp[i] = new long long[len + 2];
//     //   memset(dp[i], 0, (len + 2) * sizeof(long long));
//     // }
//     memset(dp, 0, sizeof(dp));
//     long long maxCnt = 0;
//     if (len == 0)
//       return 0;
//     //初始 dp[0][len]=0
//     //拿走一个那就是max(dp[1][len]=dp[0][len]+card[0],dp[0][len-1]=dp[0][len]+card[len-1])
//     for (size_t i = 0; i <= k; i++) {                   // head
//       for (size_t j = len + 1; j >= len - k + 1; j--) { // tail

//         if (i != 0 && j != len + 1)
//           dp[i][j] = max(dp[i - 1][j] + cardPoints[i - 1],
//                          dp[i][j + 1] + cardPoints[j - 1]);
//         else if (i != 0) {
//           dp[i][j] = dp[i - 1][j] + cardPoints[i - 1];
//         } else if (j != len + 1) {
//           dp[i][j] = dp[i][j + 1] + cardPoints[j - 1];
//         }

//         // if (j - i == len + 1 - k) {
//         //   maxCnt = max(maxCnt, dp[i][j]);
//         //   break;
//         // }
//       }
//     }

//     for (size_t i = 0; i <= k; i++) {
//       maxCnt = max(maxCnt, dp[i][i + len + 1 - k]);
//     }
//     // for (size_t i = 0; i < len + 2; i++) {
//     //   delete[] dp[i];
//     // }
//     // delete[] dp;
//     return maxCnt;
//   }
// };
/* 搞了半天结果是滑动窗口的题，上面的动态规划爆栈了 */
class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int sum = 0;
    int sum2 = 0;
    int minCnt = INT_MAX;
    int len = cardPoints.size();

    if (!k || !len)
      return 0;
    for (int i = 0; i != len; i++) {
      sum += cardPoints[i];
      sum2 += cardPoints[i];
      if (i >= len - k) { //淘汰
        sum -= cardPoints[i - (len - k)];
      }
      if (i >= len - k - 1) {
        minCnt = min(sum, minCnt);
      }
    }
    return sum2 - minCnt;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  // max=dp[5][7]
  vector<int> v{9, 7, 7, 9, 7, 7, 9};
  int point = s.maxScore(v, 7);
  std::cout << point << std::endl;
  return 0;
}
