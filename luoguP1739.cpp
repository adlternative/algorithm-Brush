//
// Created by adl on 2020/12/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<char> stk;

    bool isValid(string &&s) {
        for (const auto &item:s) {
            if (item == '(') {
                stk.push(item);
            } else if (item == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else if (stk.empty()) {
                    return false;
                } else {
                    stk.push(item);
                }
            } else {
                continue;
            }
        }
        return stk.empty();
    }
};

int main(int argc, char *argv[]) {
    string str;
    cin >> str;
    Solution s;
    std::cout << (s.isValid(std::move(str)) ? "YES" : "NO") << std::endl;

    return 0;
}