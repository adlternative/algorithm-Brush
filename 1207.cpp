//
// Created by adl on 2020/10/28.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    map<int, int> cnt;
    set<int> s;
    bool flag;

    bool uniqueOccurrences(vector<int> &arr) {
        flag = true;
        for (const auto &item:arr) {
            auto p = cnt.find(item);
            if (p==cnt.end()) {
                cnt[item]=1;
            } else {
                p->second++;
            }
        }

        for_each(cnt.begin(), cnt.end(), [&](const pair<int, int> p) {
            if (s.find(p.second) != s.end()) {
                flag = false;
            } else{
                s.insert(p.second);
            }
            
        });
//        for (const auto &item1:s) {
//            std::cout << item1 << std::endl;
//
//        }

        return flag;
    }
};


int main(int argc, char *argv[]) {
    vector<int> arr = {1, 2,2};
    Solution s;
    auto ans = s.uniqueOccurrences(arr);
    std::cout << ans << std::endl;

    return 0;
}