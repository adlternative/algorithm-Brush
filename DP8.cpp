#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Soultion {
public:
  int sum(int n, vector<int> &v) {
    // 包含 v[i] 的正数组长度
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = v[0] > 0 ? 1 : 0;
    int ret = dp[1];
    int oldest_neg = v[0] < 0 ? 0 : -1;
    for (int i = 2; i <= n; i++) {
      if (v[i - 1] > 0) {
        dp[i] = dp[i - 1] + 1;
      } else if (v[i - 1] < 0) {
        if (oldest_neg == -1) {
          dp[i] = 0;
          oldest_neg = i - 1;
        } else {
          dp[i] = i - 1 - oldest_neg + dp[oldest_neg] + 1;
        }
      } else {
        dp[i] = 0;
        oldest_neg = -1;
      }
      ret = max(ret, dp[i]);
    }
    // for (int i = 0; i <= n; i++)
    //   std::cout << dp[i] << " ";
    // std::cout << std::endl;
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  Soultion s;
  cout << s.sum(n, v) << endl;
}