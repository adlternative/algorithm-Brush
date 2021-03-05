//
// Created by adl on 2020/11/5.
//

#include<bits/stdc++.h>

using namespace std;
/*set : hit,hot,dot,lot,dog，log ,cog*/
/*queue :dog,log，cog*/

/*hit1 hot2 dot3 lot3 dog4 log4 cog5*/


/*hit ->hot ->dot ->dog ->cog*/
class Solution {
//    stack<string> stk;
    queue<string> q;
    map<string, int> m;

    bool dif_of_one_ch(const string &lhs, const string &rhs) {
        if (lhs == rhs)
            return false;
        int len = lhs.size();
        int dif = 0;
        for (int i = 0; i != len; ++i) {
            if (lhs[i] != rhs[i]) { dif++; }
            if(dif>1)return false;
        }
        return dif == 1;
    }


public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
//        wordList.erase();
        unordered_set<string>word_set(wordList.begin(),wordList.end());
        m.insert({beginWord, 1});
        q.push(beginWord);
        word_set.erase(beginWord);
        while (!q.empty()) {
            vector<string>temp;
            for (const auto &item:word_set) {
                /* 如果当前单词和字典中的单词只差1个字符,并且它不在map中出现 */
                if (dif_of_one_ch(q.front(), item) ) {
                    q.push(item);
                    m.insert({item, m[q.front()] + 1});
                    temp.push_back(item);
                    if (item == endWord) {
                        return m[q.front()] + 1;
                    }
                }
            }
            for (const auto &item:temp) {
                word_set.erase(item);
            }
            q.pop();
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v;
    v.emplace_back("hot");
    v.emplace_back("dot");
    v.emplace_back("dog");
    v.emplace_back("lot");
    v.emplace_back("log");
    v.emplace_back("cog");
    auto len = s.ladderLength("hit", "cog", v);
    std::cout << len << std::endl;
    return 0;
}