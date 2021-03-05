//
// Created by adl on 2020/8/1.
//

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    string s;
    stack<int> stk;
    string t;
    cin >> s;
    for (int i = 0; i != s.size(); ++i) {
        if (isdigit(s[i])) {
            t += (s[i]);
//            stk.push(s[i] - '0');
        }
        else if (ispunct(s[i])) {
            if (s[i] == '.') {
                t.push_back('\0');
                stk.push(atoi(t.c_str()));
                t.clear();
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int ob1 = stk.top();
                stk.pop();
                int ob2 = stk.top();
                stk.pop();

                if (s[i] == '+') {
                    stk.push(ob1 + ob2);
                } else if (s[i] == '-') {
                    stk.push(ob2 - ob1);
                } else if (s[i] == '*') {
                    stk.push(ob1 * ob2);

                } else if (s[i] == '/') {
                    stk.push(ob2 / ob1);
                }
            } else if (s[i] == '@') {
                cout << stk.top();
                stk.pop();
            }
        }

    }


    return 0;
}