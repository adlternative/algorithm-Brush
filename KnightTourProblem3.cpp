//
// Created by adl on 2020/9/27.
//
#include<bits/stdc++.h>
//#include <zconf.h>

#define N 8
using namespace std;

struct node {
    int x;
    int y;

    int dirtIndex;

    node(int x, int y, int dirtIndex) : x(x), y(y),dirtIndex(dirtIndex) {}
};

class Solution {
public:
    void init() {
        cnt = 1;
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                mapp[i][j] = 0;
            }
        }
        while (!stk.empty()) {
            stk.pop();
        }
    }

    Solution() : sum(0), cnt(1) {}

    void print() {
        puts("地图：");
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                std::cout << mapp[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printStk() {
        puts("栈中：");
        while (!stk.empty()) {
            printf("(%d,%d)<- ", stk.top().x, stk.top().y);
            stk.pop();
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }

    bool overRange(int x, int y) {
        return x >= N || y >= N || x < 0 || y < 0;
    }

    bool haveUsed(int x, int y) {
        return mapp[x][y] > 0;
    }

    int begx, begy;
    stack<node> stk;
    int mapp[N][N];
    int cnt;
    int sum;
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

    /*   bool dfs(int x, int y, int dep) {
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
               } else {
                   return true;
               }
           }
           mapp[x][y] = 0;
           cnt--;
           return false;

       }
   */

    bool dfs() {
        while (1) {
            if (cnt == N * N + 1) {
                return true;
            }
            vector<pair<int, int>> next(8, {0, 0});/*x为方向的坐标,y是该方向下一个节点的权值*/
            for (int i = 0; i != 8; ++i) {
                next[i].first = i;
                int nextx = stk.top().x + dirt[i][0];
                int nexty = stk.top().y + dirt[i][1];
                if (overRange(nextx, nexty) || haveUsed(nextx, nexty)) {
                    continue;
                }
                for (int j = 0; j != 8; ++j) {
                    int nextxx = nextx + dirt[j][0];
                    int nextyy = nexty + dirt[j][1];
                    if (overRange(nextxx, nextyy) || haveUsed(nextxx, nextyy)) {
                        continue;
                    }
                    next[i].second++;
                }
            }
            sort(next.begin(), next.end(),
                 [&](const pair<int, int> &s1, const pair<int, int> &s2) { return s1.second < s2.second; });
            /*for (const auto &item:next) {
                std::cout << "dirt:" << item.first << " value:" << item.second << std::endl;
            }*/
//            exit(1);
            int k;
            for (k = stk.top().dirtIndex + 1; k != 8; ++k) {
                int d = next[k].first;/*下一个方向在dict的坐标*/
                int nextx = stk.top().x + dirt[d][0];
                int nexty = stk.top().y + dirt[d][1];
                stk.top().dirtIndex++;
                if (!overRange(nextx, nexty) && !haveUsed(nextx, nexty)) {
                    stk.push(node(nextx, nexty, -1));
//                    std::cout << "push" << nextx << " " << nexty << " " << cnt << endl;
                    mapp[nextx][nexty] = cnt++;

                    break;
                }
            }
            if (stk.top().dirtIndex >= 7) {
                if (stk.top().x == begx && stk.top().y == begy) {
                    puts("失败");
                    return false;
                }
                mapp[stk.top().x][stk.top().y] = 0;
                stk.pop();
                cnt--;
            }
        }
    }

    void KnightTour() {
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                init();
                begx = i;
                begy = j;
                stk.push(node(begx, begy, -1));
                mapp[begx][begy] = cnt++;
                if (dfs()) {
                    std::cout << "第" << sum++ << "次试验成功" << std::endl;
                    print();
                    printStk();
                } else {
                    std::cout << "第" << sum++ << "次试验失败" << std::endl;
                }
            }
        }
/*
        cout << "x:";
        cin >> begx;
        cout << "y:";
        cin >> begy;
*/
    };

};

int main(int argc, char *argv[]) {
    Solution s;
    s.KnightTour();
    return 0;
}