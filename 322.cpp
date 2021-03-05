//
// Created by adl on 2020/11/30.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        }
        int size = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i != amount + 1; ++i) {
            for (int j = 0; j != size; ++j) {
                int cnt = i - coins[j];
                if (cnt < 0||dp[cnt]==INT_MAX) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[cnt]);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{3, 6, 13};

    std::cout << s.coinChange(v, 14) << std::endl;

    return 0;
}