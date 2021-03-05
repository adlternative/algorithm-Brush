//
// Created by adl on 2020/11/8.
//

#include<bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    Solution() : ret(0) {}
//
//    int ret;
//
//    int maxProfit(vector<int> &prices) {
//        int s = prices.size();
//        int cur = 0;
//        while (cur != s) {
//            int temp = cur;
//            while (temp + 1 != s && prices[temp] < prices[temp + 1]) {
//                temp++;
//            }
//            ret += prices[temp] - prices[cur];
////            std::cout << temp <<" !"<< cur << std::endl;
//            cur = temp+1;
//        }
//        return ret;
//    }
//};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int day = prices.size();/*天数*/
        if (day == 0) {
            return 0;
        }
        int dp[day][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i != day; ++i) {
            if (i == 0) {
                dp[i][0] = 0;/*第一天不买票的收益*/
                dp[i][1] = -prices[i];/*第一天买票的收益*/
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            /*今天没票的情况下钱最多是/昨天没票：啥也不做/昨天有票：昨天的钱+卖票的钱*/
                            /*　昨天有票　　*/
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            /*今天有票的情况下钱最多是/昨天没票：昨天的钱－买票的钱/昨天有票：啥也不做/昨天有票：昨天的钱+卖票的钱-买票的钱*/
        }
        return dp[day - 1][0];

    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5};
    int som = s.maxProfit(v);
    std::cout << som << std::endl;
    return 0;
}