//
// Created by adl on 2020/12/10.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int day = prices.size();
        int dp[day][3][2];
        memset(dp, 0, sizeof(dp));
        /*第0天，允许0次交易*/
        dp[0][0][1] = INT_MIN;
        for (int i = 0; i != day; ++i) {
            for (int j = 1; j != 3; ++j) {
                if (i == 0) {
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[day - 1][2][0];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5};
    int a = s.maxProfit(v);
    std::cout << a << std::endl;

    return 0;
}
