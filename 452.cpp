//
// Created by adl on 2020/11/23.
//

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int size = points.size();
        if (!size)return 0;
        sort(points.begin(), points.end());
        int arrowSize = 1;
        pair<int, int> range = {points[0][0], points[0][1]};//1 2

        for (int i = 1; i < size; i++) {
            auto &j = points[i];//2 3
            if (range.second >= j[0]) {//寻找共同区间
                range.first = j[0];
                range.second = min(j[1], range.second);
            } else {
                arrowSize++;
                range.first = j[0];
                range.second = j[1];
            }
        }
        return arrowSize;
    }
};

/*
寻找最大共有2 6
 0
    1 6 --->(2,6)
    2 8
 1
 若将要重叠，继续1
 否则+1,
 range->(7,12)

    7 12  ---- >(10 - 12)
    10 16

 * | 2 8 | 1 6 | 7-12 |
 * */
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> points;
//    [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
    /*
     * 0 6
     * 0 9
     * 2 8
     * 2 9
     * 3 9
     * 3 9
     *
     * */
    points.push_back({3, 9});
    points.push_back({7, 12});
    points.push_back({3, 8});
    points.push_back({6, 8});
    points.push_back({9, 10});
    points.push_back({2, 9});
    points.push_back({0, 9});
    points.push_back({3, 9});
    points.push_back({0, 6});
    points.push_back({2, 8});
    auto ret = s.findMinArrowShots(points);
    std::cout << ret << std::endl;

    return 0;
}