//
// Created by adl on 2020/12/3.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    int sum{};

    bool isValid(vector<string> &v, int cnt, int i) {
        // [1][4] 不能要[0][3],[2][5] ,[3][6]...[6][7]
        // y=x+3
        //y=5-x
        for (int j = 0; j != sum; ++j) {
            if (v[cnt][j] == 'Q') {
                return false;
            }
        }
        for (int j = 0; j != sum; ++j) {
            if (cnt + i - j < 0 || cnt + i - j >= sum) {
                continue;
            }
            if (v[j][cnt + i - j] == 'Q') {
                return false;
            }
        }
        for (int j = 0; j != sum; ++j) {
            if (j + i - cnt < 0 || j + i - cnt >= sum) {
                continue;
            }
            if (v[j][j + i - cnt] == 'Q') {
                return false;
            }
        }
        for (int j = 0; j != sum; ++j) {
            if (v[j][i] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<string> &v, int cnt) {
        if (cnt== sum) {
            ret.push_back(v);
            return;
        }
        for (int i = 0; i < sum; i++) {
            if (!isValid(v, cnt, i)) {
                continue;
            }
            v[cnt][i] = 'Q';
            dfs(v, cnt + 1);
            v[cnt][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        sum = n;
        vector<string> v(n, string(n, '.'));
        dfs(v, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto vv = s.solveNQueens(4);
    for (const auto &item:vv) {
        for (const auto &it:item) {
            std::cout << it << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}