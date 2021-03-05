//
// Created by adl on 2020/11/30.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N < 1)return 0;
        if (N == 2 || N == 1)return 1;
        int pre = 1, cur = 1;
        vector<int> dp(N, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i != N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N-1];
        //        for (int i = 3; i <= N; ++i) {
//            int sum = cur + pre;
//            pre = cur;
//            cur = sum;
//        }
        return cur;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    /* 1 1 2 3 5*/
    std::cout << s.fib(4) << std::endl;

    return 0;
}
