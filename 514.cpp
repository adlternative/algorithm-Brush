//
// Created by adl on 2020/11/11.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];
        for (int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }
//        for (int i = 0; i != 26; ++i) {
//            std::cout<<(char)(i+'a')<<":"  ;
//            for (const auto &item:pos[i]) {
//                std::cout << item << " ";
//            }
//            std::cout  << std::endl;
//
//        }

        int dp[m][n];

        /* dp 在key 为第m0个，ring为第n0最少的次数 */

        memset(dp, 0x3f3f3f3f, sizeof(dp));
//        std::cout << key[0] << std::endl; 'g'

        for (auto& i: pos[key[0] - 'a']) {
        /* i  0  6*/
//        dp[0][0]=min(0,7)+1=1;
//        dp[0][6]=min(6,1)+1=2;
            dp[0][i] = min(i, n - i) + 1;
        }

//        for(int i  = 0 ;i<m;i++){
//            for(int j = 0 ;j<n ;j++){
//                printf("%d ",dp[i][j]);
//            }
//            printf("\n");
//        }

        for (int i = 1; i < m; ++i) {//i是key的所有index
                for (auto& k: pos[key[i - 1] - 'a']) {//k是　前一个字符的所有ring坐标
                    for (auto& j: pos[key[i] - 'a']) {//j是key当前字符的所有ring坐标
                    /*dp最小值=当前最小值 或者 在不包含当前字符的的最小dp+在所有j的可能下的所有k的可能下的最小移动距离+1 */
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1], dp[m - 1] + n);
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    int time = s.findRotateSteps("godding", "gd");
    std::cout << time << std::endl;
    return 0;
}