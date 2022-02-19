#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<int> dp(n);
    dp[0] = 1;
    int lens = primes.size();
    vector<int> p(lens, 0);
    for (int i = 1; i < n; i++) {
      dp[i] = INT_MAX;
      int jj;
      for (int j = 0; j < lens; j++) {
        int s = primes[j] * dp[p[j]];
        while (s <= dp[i - 1]) {
          p[j]++;
          s = primes[j] * dp[p[j]];
        }
        if (dp[i] > s) {
          dp[i] = s;
          jj = j;
        }
      }
      p[jj]++;
    }
    // for (int j = 0; j < n; j++)
    //   std::cout << dp[j] << " ";
    // std::cout << std::endl;
    return dp[n - 1];
  }
};
TEST(Solution, isMatch) {
  Solution s;

  vector<int> v{3, 5, 7, 11, 19, 23, 29, 41, 43, 47};
  EXPECT_EQ(s.nthSuperUglyNumber(15, v), 35);
}
