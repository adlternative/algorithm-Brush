#include <bits/stdc++.h> /* 万能头 */
#include <iostream>

using namespace std;

int dfs(vector<vector<int>> &vv, vector<bool> &visit, int index, int m) {
  int n = vv.size();
  int max_count = 0;

  if (index == n)
    return max_count;

  for (int i = index; i < n; i++) {
    if (vv[i][0] <= m && vv[i][1] <= m && !visit[vv[i][0]] &&
        !visit[vv[i][1]] && vv[i][0] != vv[i][0]) {
      visit[vv[i][0]] = visit[vv[i][1]] = true;
      max_count = max(max_count, dfs(vv, visit, i + 1, m) + 1);
      visit[vv[i][0]] = visit[vv[i][1]] = false;
    }
  }
  return max_count;
}

int main(int argc, char *argv[]) {
  int n, m;
  // n 个客人  [1,m] 范围
  cin >> n >> m;
  int v[n][2];

  int max_count = 0;
  vector<vector<int>> vv(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> vv[i][0] >> vv[i][1];

  vector<bool> visit(m + 1);

  for (int i = 0; i < n; i++) {
    if (vv[i][0] <= m && vv[i][1] <= m && !visit[vv[i][0]] &&
        !visit[vv[i][1]]) {
      visit[vv[i][0]] = visit[vv[i][1]] = true;
      max_count = max(max_count, dfs(vv, visit, i + 1, m) + 1);
      visit[vv[i][0]] = visit[vv[i][1]] = false;
    }
  }

  std::cout << max_count << std::endl;
}