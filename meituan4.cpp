#include <bits/stdc++.h> /* 万能头 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++)
    cin >> v[i];

  /* m -> time  n -> 房间*/
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

  // dp[0][0] = INT_MAX;
  dp[0][1] = 0;
  // for (int i = 2; i <= n; i++)
  //   dp[0][i] = INT_MAX;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[i - 1] == j)
        dp[i][j] = INT_MAX;
      else {
        for (int k = 1; k <= n; k++) {
          if (dp[i - 1][k] == INT_MAX)
            continue;
          dp[i][j] = min(dp[i - 1][k] + abs(k - j), dp[i][j]);
        }
      }
    }
  }

  int min_v = INT_MAX;
  for (int i = 1; i <= n; i++)
    min_v = min(min_v, dp[m][i]);
  cout << min_v << endl;
}