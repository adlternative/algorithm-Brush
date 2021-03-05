//
// Created by adl on 2020/12/4.
//

#include<bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    vector<string> getAdj(string s, set<string> &sSet) {
        vector<string> sv;
        string cur = s;
        for (int i = 0; i != 4; ++i) {
            cur[i] = (s[i] - '0' + 1 + 10) % 10 + '0';
            sv.push_back(cur);
            cur[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            sv.push_back(cur);
            cur[i] = s[i];
        }
        return sv;
    }

    int openLock(vector<string> &deadends, string target) {
        if (find(deadends.begin(), deadends.end(), target) != deadends.end() ||
            find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }
        int depth = 0;
        queue<string> sq;
        set<string> visited;
        set<string> dead;
        dead.insert(deadends.begin(), deadends.end());
        sq.push("0000");
        visited.insert("0000");

        while (!sq.empty()) {
            int size = sq.size();
            for (int i = 0; i != size; ++i) {
                auto cur = sq.front();
                sq.pop();
                if (target == cur) {
                    return depth;
                }
                auto vec = getAdj(cur, dead);
                for (int j = 0; j != vec.size(); j++) {
                    if (visited.find(vec[j]) == visited.end() &&dead.find(vec[j]) == dead.end()){
                        sq.push(vec[j]);
                        visited.insert(vec[j]);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
*/

class Solution {
public:
    vector<string> getAdj(string s) {
        vector<string> sv;
        string cur = s;
        for (int i = 0; i != 4; ++i) {
            cur[i] = (s[i] - '0' + 1 + 10) % 10 + '0';
            sv.push_back(cur);
            cur[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            sv.push_back(cur);
            cur[i] = s[i];
        }
        return sv;
    }

    int openLock(vector<string> &deadends, string target) {
        if (find(deadends.begin(), deadends.end(), target) != deadends.end() ||
            find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }
        set<string> visited1;
        set<string> visited2;
        set<string> dead(deadends.begin(), deadends.end());
        queue<string> q1;
        queue<string> q2;
        visited1.insert("0000");
        q1.push("0000");
        visited2.insert(target);
        q2.push(target);

        int depth1 = 0;
        int depth2 = 0;
        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size();
            for (int i = 0; i < size1; i++) {
                auto cur = q1.front();
                q1.pop();
                if (visited2.find(cur) != visited2.end()) {
                    return depth1 + depth2;
                }
                auto vec = std::move(getAdj(cur));
                for (int j = 0; j != vec.size(); j++) {
                    if (visited1.find(vec[j]) == visited1.end() && dead.find(vec[j]) == dead.end()) {
                        q1.push(vec[j]);
                        visited1.insert(vec[j]);
                    }
                }
            }
            depth1++;

            int size2 = q2.size();
            for (int i = 0; i < size2; i++) {
                auto cur = q2.front();
                q2.pop();
                if (visited1.find(cur) != visited1.end()) {
                    return depth1 + depth2;
                }
                auto vec = std::move(getAdj(cur));
                for (int j = 0; j != vec.size(); j++) {
                    if (visited2.find(vec[j]) == visited2.end() && dead.find(vec[j]) == dead.end()) {
                        q2.push(vec[j]);
                        visited2.insert(vec[j]);
                    }
                }
            }
            depth2++;
        }
        return -1;
    }

};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    int a = s.openLock(deadends, "0202");
    std::cout << a << std::endl;

    return 0;
}