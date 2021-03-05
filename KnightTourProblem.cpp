//
// Created by adl on 2020/9/2N.
//

#include<bits/stdc++.h>
#include <zconf.h>

#define N 5
using namespace std;

class Solution {
public:
    Solution() : cnt(0) {
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                mapp[i][j] = 0;
            }
        }
    }

    int mapp[N][N];
    int cnt;
    const int dirt[8][2]{
            {1,  2},
            {1,  -2},
            {2,  1},
            {2,  -1},
            {-1, 2},
            {-1, -2},
            {-2, 1},
            {-2, -1}
    };

    bool dfs(int x, int y, int dep) {


        if (x >= N || y >= N || x < 0 || y < 0) {
            return false;
        }

        if (mapp[x][y]) {
            return false;
        }
        mapp[x][y] = dep;
        cnt++;
        std::cout << "try " << x << " " << y << std::endl;
        std::cout << cnt << std::endl;
        if (cnt == N * N) {
            std::cout << "成功" << std::endl;
            std::cout << "try " << x << " " << y << std::endl;
            std::cout << cnt << std::endl;
            return true;
        }
        for (int i = 0; i != 8; ++i) {
            int tox = dirt[i][0];
            int toy = dirt[i][1];

            if (dfs(x + tox, y + toy, dep + 1) == false) {
                continue;
            }else {
                return  true ;
            }
        }
        mapp[x][y] = 0;
        cnt--;
        return false;

    }

    void KnightTour() {
        int num = 0;
        for (int x = 0; x != N; ++x) {
            for (int y = 0; y != N; ++y) {

                for (int i = 0; i != N; ++i) {
                    for (int j = 0; j != N; ++j) {
                        mapp[i][j] = 0;
                    }
                }

                cnt = 0;
                std::cout << "start in（" << x << "," << y << ")" << std::endl;

                //        cnt++;
//        mapp[x][y] = true;
                if (dfs(x, y, 1)) {
                    num++;
                    std::cout << "num:" << num << std::endl;

                    for (int i = 0; i != N; ++i) {
                        for (int j = 0; j != N; ++j) {
                            std::cout << mapp[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "!!!" << std::endl;
                    sleep(1);
                } else {
                    for (int i = 0; i != N; ++i) {
                        for (int j = 0; j != N; ++j) {
                            std::cout << mapp[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "???" << std::endl;
                    sleep(1);

                }
            }
        }
//        int x = 0/*rand() % N*/;
//        int y = 0/*rand() % N*/;

    }
};


int main(int argc, char *argv[]) {
    Solution s;
    s.KnightTour();
    return 0;
}