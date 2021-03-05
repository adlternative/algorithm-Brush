//
// Created by adl on 2020/11/16.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>>que;
        for (const auto &peo:people) {
            auto it=que.begin();
            std::advance(it,peo[1]);
            it =que.insert(it,peo);
        }

        return vector<vector<int>>(que.begin(),que.end());
    }
};


int main(int argc, char *argv[]) {
    Solution S;
    vector<vector<int>> vv;
    vector<int> v1{7, 0};
    vector<int> v2{4, 4};
    vector<int> v3{7, 1};
    vector<int> v4{5, 0};
    vector<int> v5{6, 1};
    vector<int> v6{5, 2};
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    vv.push_back(v6);
    auto ret = S.reconstructQueue(vv);
    for (const auto &i:ret) {
        std::cout << i[0] << " " << i[1] << std::endl;
    }
    return 0;
}