//
// Created by adl on 2020/11/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    class cmp {
    public:
        bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
            return l.first > r.first;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<vector<int>> ret;

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        int size = points.size();
        for (int i = 0; i != size; ++i) {
            pq.push({pow(points[i][0], 2) + pow(points[i][1], 2), i});
        }

        while (!pq.empty()&&K--) {
            ret.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> vv;
    vector<int> v1{1, 3};
    vector<int> v2{-2, 2};
    vector<int> v3{2, 3};
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    auto v = std::move(s.kClosest(vv, 2));

    for (const auto &item:v) {
        printf("[");
        for (const auto &it:item) {
            std::cout << "[";
            std::cout << it ;
            std::cout << "]";
            std::cout  << std::endl;
        }
        printf("]");

    }
    return 0;
}