//
// Created by adl on 2020/11/25.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        string ret;
        map<char, int> u_map;
        for (const auto &item:s) {
            auto it = u_map.find(item);
            if (it == u_map.end()) {
                u_map[item] = 1;
            } else {
                it->second++;
            }
        }
        while (1) {
            int flag = 0;
            for (auto i = u_map.begin(); i != u_map.end(); ++i) {
                if (i->second == 0) {
                    continue;
                }
                flag =1;
                ret.push_back(i->first);
                i->second--;
            }
            if(flag ==0){
                return ret;
            }
            for (auto i = u_map.rbegin(); i != u_map.rend(); ++i) {
                if (i->second == 0) {
                    continue;
                }
                flag =0;
                ret.push_back(i->first);

                i->second--;
            }
            if(flag ==1){
                return ret;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string ss = s.sortString("ggggggg");
    std::cout << ss << std::endl;
    return 0;
}
