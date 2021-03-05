//
// Created by adl on 2020/9/13.
//
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:

    int row;
    int col;
//    map<pair<int, int>, bool> mapp;
    vector<vector<int>>mapp;
    pair<int, int> dist[4] = {{1,  0},
                              {0,  1},
                              {-1, 0},
                              {0,  -1}};
    bool dfs(int i, int j, int cnt, const string &word, vector<vector<char>> &board) {

        if (cnt == word.size() /*- 1*/) {//12
//            cout << i << " " << j << endl;
            return true;
        }

        if (i >= row || i < 0 || j >= col || j < 0) {
            return false;
        }

        if ((mapp[i][j])) {
            return false;
        }

        if (word[cnt] != board[i][j]) {
            return false;
        }
        mapp[i][j] = true;
        if (dfs(i + 1, j, cnt + 1, word, board) == true) {
            return true;
        }
        if (dfs(i, j + 1, cnt + 1, word, board) == true) {
            return true;
        }
        if (dfs(i, j - 1, cnt + 1, word, board) == true) {
            return true;
        }
        if (dfs(i - 1, j, cnt + 1, word, board) == true) {
            return true;
        }
        mapp[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {

        if (word[0] == '\0') {
            return false;
        }
        row = board.size();
        col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        mapp =visited ;
        for (int i = 0; i != row; ++i) {
            auto bb = board[i];
            for (int j = 0; j != col; ++j) {
                if (bb[j] == word[0]) {
                    if (dfs(i, j, 0, word, board) == true) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool check(vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[k]) return false;

        visited[i][j] = true;

        if (check(board, visited, word, i - 1, j, k + 1))
            return true;
        if (check(board, visited, word, i, j - 1, k + 1))
            return true;
        if (check(board, visited, word, i + 1, j, k + 1))
            return true;
        if (check(board, visited, word, i, j + 1, k + 1))
            return true;
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {

        if (board.empty() || board[0].empty()) return false;
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w, 0));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (check(board, visited, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
/*
 * caa
 * aaa
 * bcd */

/*
 *[["a","a","a"],["a","b","b"],["a","b","b"],["b","b","b"],["b","b","b"],["a","a","a"],["b","b","b"],["a","b","b"],["a","a","b"],["a","b","a"]]
 *
 *
 * aaa
 * abb
 * abb
 * bbb
 * bbb
 * aaa
 * bbb
 * abb
 * aab
 * aba
 * aabaaaabb
 * */

/*
 *
a
a
a
a
b
b
a
b
b
b
b
b
b
b
b
a
a
a
b
b
b
a
b
b
a
a
b
a
b
a
*/
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char>> vv;
    char x;
    for (int i = 0; i != 3; ++i) {
        vector<char> v;
        for (int j = 0; j != 3; ++j) {
            cin >> x;
            v.push_back(x);
        }
        vv.push_back(v);
    }
    if (s.exist(vv, "aab"))
        cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}