//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPwd(int i, string &&src) {
        string ret;
        for (const auto &item:src) {
            /* z-a=25 (25+3)%26=2*/
            ret.push_back((item - 'a' + i) % 26 + 'a');
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    int i;
    string str;
    cin >> i >> str;
    Solution s;
    string ss = std::move(s.getPwd(i, std::move(str)));
    std::cout << ss << std::endl;

    return 0;
}