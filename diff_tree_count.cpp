#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Soultion {
public:
  int diffTreeCount(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      //选取 k 为 root 节点
      for (int k = 0; k < i; k++) {
        if (k == 0 || k == i - 1)
          dp[i] += dp[i - 1];
        else
          dp[i] += dp[k] * dp[i - 1 - k];
      }
    }

    return dp[n];
  }
};

int main() {
  int n;
  cin >> n;
  Soultion s;
  cout << s.diffTreeCount(n) << endl;
}