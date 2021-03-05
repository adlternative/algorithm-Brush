//
// Created by adl on 2020/10/30.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() : sum(0) {}

private:
    int sum;
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int sz = grid.size();
        int col = grid[0].size();

        for (int i = 0; i != sz; ++i) {
            for (int j = 0; j != col; ++j) {
                int s = 4;
                if (grid[i][j] == 1) {

                    if (i + 1 != sz ) {
                        if (grid[i + 1][j ] == 1) {
                            s--;
                        }
                    }
                    if ( j != 0) {
                        if (grid[i ][j - 1] == 1) {
                            s--;
                        }
                    }
                    if (i != 0) {
                        if (grid[i - 1][j ] == 1) {
                            s--;
                        }
                    }
                    if (j + 1 != col) {
                        if (grid[i ][j + 1] == 1) {
                            s--;
                        }
                    }
                    sum += s;
                }
            }
        }
        return sum;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1, 1};
    vector<vector<int>> vv;
    vv.push_back(v);
    auto a = s.islandPerimeter(vv);
    std::cout << a << std::endl;

    return 0;
}
