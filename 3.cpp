//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int left = 0, right = 0;
        int maxlen = 0;
        unordered_map<char, int> window;
        while (right != s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] == 2) {/*如果有个元素出现了重复*/
                /*我们及时进行记录*/
//                std::cout << left << right << std::endl;
                maxlen = max(maxlen, right - left - 1);
                char cc = s[left];
                left++;
                window[cc]--;
//                std::cout << left<<right << std::endl;
                if (cc == c) {
                    /*如果刚才重复的字符已经及时的删除了*/
//                    std::cout << left<<right << std::endl;

                    continue;
                }
            }
        }
        if(right==s.size()){
            maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int len = s.lengthOfLongestSubstring(" ");
    std::cout << len << std::endl;

    return 0;
}