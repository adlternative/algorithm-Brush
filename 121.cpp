//
// Created by adl on 2020/12/10.
//

#include<bits/stdc++.h>

using namespace std;

/*
 * 1次交易，限制了dp[i][1]，保证这次交易前没有交易
 *             dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] -prices[i]);
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int day = prices.size();/*天数*/
        if (day == 0) {
            return 0;
        }
        int dp[day][2];
        memset(dp, 0, sizeof(dp));
        /*stat1:第x天
         *stat2:持有,不持有
         *dp[stat1][stat2]=maxMoney 　
         */
        for (int i = 0; i != day; ++i) {
            if (i == 0) {
//                dp[0][0]=max(dp[0][0],dp[-1][1]+prices[0]);//
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1],/* dp[i - 1][0]*/ -prices[i]);

        }
//        for (int i = 0; i < day; i++) {
//            for (int j = 0; j != 2; ++j) {
//                std::cout << dp[i][j] << " ";
//            }
//            std::cout << std::endl;
//
//        }
        return dp[day - 1][0];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{7, 1, 5, 3, 6, 4};
    int p = s.maxProfit(v);
    std::cout << p << std::endl;
    return 0;
}