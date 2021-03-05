//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ret;
        unordered_map<char, int> need, window;
        for (auto c:s1)need[c]++;
        int valid = 0;
        int left = 0, right = 0;

        while (right != s2.size()) {
            char c = s2[right];/*　当前右边字符　*/
            right++;
            window[c]++;
            if (need.count(c) > 0) {/*如果当前右边字符在需求字符串中*/
                if (window[c] == need[c]) {/*如果个数对的上*/
                    valid++;
                }
            }
            while (valid == need.size()) {
                /*如果当前字符串满足需求数量*/
                char cc = s2[left];
                left++;
                window[cc]--;
                if (need.count(cc) > 0) {
                    if (window[cc] == need[cc] - 1) {
                        valid--;
                        if (right - left + 1 == s1.size()) {
                            /*在结果集中记录失效前的一个点的位置*/
                            ret.push_back(left - 1);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto ve = std::move(s.findAnagrams("baa", "aa"));
    for (const auto &item:ve) {
        std::cout << item << std::endl;
    }
    return 0;
}