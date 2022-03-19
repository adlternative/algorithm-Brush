#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    /*  0~9 */
    // if (n == 0)
    //   return 1;
    // else if (n == 1)
    //   return 9;
    int dp[11];
    dp[0] = 1;
    dp[1] = 9;
    int max_value = max(n, 10);
    int sum = 0;
    if (n >= 0)
      sum += dp[0];
    if (n >= 1)
      sum += dp[1];

    for (int i = 2; i <= n; i++) {
      dp[i] = (10 - i + 1) * dp[i - 1];
      sum += dp[i];
    }
    return dp[n];
    /* dp[0]=1 dp[1]=9 */
    /* dp[2]= (10-1) * dp[1]  */
    /* 1[2-0] 2[1-2 3-0] */
    /* dp[3]= (10-2) * dp[2]  */
    /* 12[3-0] */
  }
};

TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
