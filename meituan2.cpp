#include <bits/stdc++.h> /* 万能头 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  // vector<int> dp(n + 1);
  vector<vector<int>> dp(n, vector<int>(2));

  if (v[0] == 1) {
    dp[0][1] = 1;
  } else {
    dp[0][0] = 1;
  }

  for (int i = 1; i < n; i++) {
    // 包含 v[i] 生成 -1 连续数量
    // dp[i][0]
    // 包含 v[i] 生成 1 连续数量
    // dp[i][1]
    if (v[i] == 1) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + 1;
    } else {
      dp[i][0] = dp[i - 1][1] + 1;
      dp[i][1] = dp[i - 1][0];
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += dp[i][1];
  cout << sum << endl;
}