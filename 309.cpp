//
// Created by adl on 2020/12/10.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int day = prices.size();
        if (day == 0) { return 0; }
        int dp[day][2];
        memset(dp, 0, sizeof(dp));
        /*第0天，允许0次交易*/
        for (int i = 0; i != day; ++i) {
            if (i == 0) {
                dp[i][1] = INT_MIN;
                dp[i][1] = -prices[i];/*第一天买票的收益*/
                continue;
            }
            if (i == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
                /*昨天有票，没卖/昨天没有票，今天买/*/
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], (dp[i - 1][1] + prices[i]));
            /*今天没票的情况下钱最多是/昨天没票：啥也不做/昨天有票：昨天的钱+卖票的钱*/
            /*卖票自由啊*/

            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            /*今天有票的情况下钱最多是/昨天有票：啥也不做/
             * 昨天没票：昨天的钱－今天买票的钱(现在不能用这条了，因为我们不确定昨天是不是休息日，我们只能从前天没有买票来确定今天可以买)/
             * 前天卖掉且不买，昨天休息，今天买*/

            /*前天有票,昨天卖掉,今天买不了*/
        }
//        for (int i = 0; i != day; ++i) {
//            for (int j = 0; j != 2; j++) {
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
    vector<int> v{1, 2, 3, 0, 2};
    int a = s.maxProfit(v);
    std::cout << a << std::endl;

    return 0;
}