//
// Created by adl on 2020/11/15.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<char> stk;
    string ret;

    string removeKdigits(string num, int k) {
        int size = num.size();
        if (size == 0) {
            return num;
        }
        int cnt = 1;
        int popcnt = 0;
        stk.push_back(num[0]);
        if(size==cnt){
            return "0";
        }
        while (true) {
            if (cnt == size) {
                while(popcnt!=k){
                    stk.pop_back();
                    popcnt++;
                }
                break;
            }
            if (!stk.empty()&&stk.back() > num[cnt]) {
                stk.pop_back();
                popcnt++;
                if (popcnt == k) {
                    for (int i = cnt; i != size; ++i) {
                        stk.push_back(num[i]);
                    }
                    break;
                }
                continue;
            } else {
                stk.push_back(num[cnt]);
                cnt++;
            }
        }
        auto iter = stk.begin();
        while ((iter != stk.end()) && (*iter == '0')) {
            iter++;
        }
        ret.assign(iter, stk.end());
//        std::cout << ret << std::endl;
        if (ret.empty()) {
            ret = "0";
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string ss = s.removeKdigits("112", 1);
    std::cout << ss << std::endl;

    return 0;
}