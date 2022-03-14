#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Soultion {
public:
    int minCount(int n, vector<int>&v) {
        vector<vector<int>>dp(n, vector<int>(2,1));
        
        for (int i = 0; i < n; i++) {
            // 选择一个位置 i 作为基点
            for (int j = 0; j < i; j++) {
                if (v[i] > v[j]) {
                    dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
                } else {
                    dp[i][0] = max(1, dp[i][0]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
//             // 选择一个位置 i 作为基点
            for (int j = n - 1; j > i; j--) {
                if (v[i] < v[j]) {
                    dp[i][1] = max(dp[j][1] + 1, dp[i][1]);
                } else {
                    dp[i][1] = max(1, dp[i][1]);
                }
            }
        }
        int ret = INT_MIN;
        for (int i = 0; i < n; i++) {
            ret = max(ret, dp[i][0] + dp[i][1] -1);
        }
        ret = n - ret;
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
    cout << s.minCount(n, v) << endl;
}