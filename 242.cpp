//
// Created by adl on 2020/11/22.
//
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    Solution() {
        memset(ss, 0, sizeof(ss));
    }

    int ss[26];

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i != s.size(); ++i) {
            ss[s[i] - 'a']++;
        }
        for (int i = 0; i != t.size(); ++i) {
            ss[t[i] - 'a']--;
        }
        if (ss['j' - 'a'] > 0) {
            std::cout << "!" << std::endl;
        }
        for (int i = 0; i != 26; ++i) {
            if (ss[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto p = s.isAnagram("axncxlhjle", "xxconlaelh");
    std::cout << p << std::endl;


    return 0;
}