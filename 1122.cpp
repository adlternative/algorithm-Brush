//
// Created by adl on 2020/11/14.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> ret;
    vector<pair<int, int>> um;
    multiset<int> remember;

    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int size = arr2.size();
        for (const auto &ia : arr2) {
            um.emplace_back(ia, 0);
        }
        for (const auto &ia : arr1) {
            int i = 0;
            for (; i != size; ++i) {
                if(um[i].first==ia){
                    um[i].second++;
                    break;
                }
            }
            if (i==size) {
                remember.insert(ia);
            }
        }

        for (const auto &ia: um) {
            for (int i = 0; i != ia.second; ++i) {
                ret.push_back(ia.first);
            }
        }
        for (const auto &it: remember) {
            ret.push_back(it);
        }
        return ret;
    }

};

void test() {
    multiset<int> u;
    u.insert(5);
    u.insert(5);
    u.insert(5);
    u.insert(1);
    u.insert(6);
    u.insert(u.end(), 3);
    for (auto it = u.begin(); it != u.end(); it++) {
        std::cout << *it << std::endl;
    }

    for (const auto &i:u) {
        printf("%d ", i);
    }
    exit(0);
}

int main(int argc, char *argv[]) {
//    test();
    Solution s;
    vector<int> v1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> v2{2, 1, 4, 3, 9, 6};
    auto v = s.relativeSortArray(v1, v2);
    for (auto &&i:v) {
        std::cout << i << std::endl;
    }
    return 0;
}
