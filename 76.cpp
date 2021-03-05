//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c:t)need[c]++;

        int left = 0, right = 0;
        int valid = 0;/*表示窗口已经满足need的字符数量*/
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];/*在src的right开始向右滑动*/
            right++;
            if (need.count(c)) {/*如果在need中有此字符*/
                window[c]++;/*将窗口中字符的计数++*/
                if (window[c] == need[c]) {

                    /*如果窗口中此字符的数量和need中相同，那么将满足need的字符数量++*/
                    valid++;
                }
            }/*没这个字符就不管了*/
            while (valid == need.size()) {/*如果已经满足了need条件*/
                if (right - left < len) {/*如果有比答案更短的答案*/
                    start = left;/*更新答案：开始的位置*/
                    len = right - left;/*更新答案：长度*/
                }
                char d = s[left];
                left++;/*左移窗口*/
                if (need.count(d)) {/*如果在需求need的里面有窗口中删除的元素*/
                    if (window[d] == need[d]) {/*如果将这个字符去掉，满足need的字符数量不足*/
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.minWindow("a", "aa") << std::endl;

    return 0;
}