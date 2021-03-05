//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (const auto &item:s) {
            if (item == '{' || item == '[' || item == '(')
                stk.push(item);
            if (item == '}') {
                if (!stk.empty()&&stk.top() == '{') {
                    stk.pop();
                }else {
                    return false;
                }
            }
            if (item == ']') {
                if (!stk.empty()&&stk.top() == '[') {
                    stk.pop();
                }else {
                    return false;
                }
            }
            if (item == ')') {
                if (!stk.empty()&&stk.top() == '(') {
                    stk.pop();
                }else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isValid("]"));
    std::cout << "!" << std::endl;

    return 0;
}