//
// Created by adl on 2020/9/15.
//

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:

    bool row[9][9];
    bool col[9][9];
    bool block[3][3][9];
    vector<pair<int, int>> vpii;

    bool dfs(vector<vector<char>> &board, int cnt) {
        if (cnt == vpii.size()) {
            return true;
        }
        int i = vpii[cnt].first;
        int j = vpii[cnt].second;
        for (int num = 0; num < 9; num++) {
            if (row[i][num] || col[j][num] || block[i / 3][j / 3][num]) {
                continue;
            }

            row[i][num] = true;
            col[j][num] = true;
            block[i / 3][j / 3][num] = true;
            board[i][j]=num+'0'+1;
            if (dfs(board, cnt + 1) == true) {
                return true;
            }
            row[i][num] = false;
            col[j][num] = false;
            block[i / 3][j / 3][num] =false;
            board[i][j]='.';

        }

        return false ;
    }

    void solveSudoku(vector<vector<char>> &board) {
        memset(col,'\0',sizeof(col));
        memset(row,'\0',sizeof(row));
        memset(block,0,sizeof(block));
        if(board.empty()){
            return ;
        }
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (board[i][j] == '.') {
                    vpii.push_back({i, j});
                } else {
                    int digit =board[i][j]-'0'+1;
                    row[i][digit] = true;
                    col[j][digit] = true;
                    block[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
};
int main(int argc, char *argv[]) {
    Solution s;

//    vector vv(9,vector<char>());
    vector<vector<char>>v;
     s.solveSudoku(v);
    return 0;
}