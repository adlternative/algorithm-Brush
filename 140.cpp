//
// Created by adl on 2020/11/1.
//
#include<bits/stdc++.h>

#include <utility>

#define DEBUG(format, ...) printf(format, ##__VA_ARGS__)


using namespace std;

class Solution {
    vector<string> vs;
    vector<string> ret;
    unordered_map<int, unordered_set<string>> checkMap;/*存进来那些可以的枝*/
public:
    bool checkLast(int start_index, string s, vector<string> &wordDict) {

        bool successFlag = false;
        for (int i = 0; i != wordDict.size(); ++i) {
            //                  checkAll
            if (checkMap.find(start_index) == checkMap.end()) {
                checkMap[start_index] = unordered_set<string>();
            } else {
                auto &haveDoSet = checkMap[start_index];
                /*失败小本本上记载了，那直接略过*/
                if (haveDoSet.find(wordDict[i]) != haveDoSet.end()) {
                    continue;
                }
            }

            if (s.compare(start_index, wordDict[i].size(), wordDict[i]) == 0) {
                /*说明temp此时和字典中此单词匹配，单词入栈*/
                vs.push_back(wordDict[i]);
                /*
                std::cout << "-----" << std::endl;
                for (const auto &item:vs) {
                    std::cout << item << std::endl;
                }
                std::cout << "-----" << std::endl;
*/
                start_index += wordDict[i].size();

                if (start_index == s.size()) {
                    /*说明此时已经把字符串填满了，那么将vector中所有的str合并加入ret中*/
                    string r_str;
                    for (int j = 0; j != vs.size() - 1; ++j) {
                        r_str += vs[j] + " ";
                    }
                    r_str += vs.back();
                    ret.push_back(std::move(r_str));
//                    std::cout << "deal" << std::endl;

                    vs.pop_back();
                    start_index -= wordDict[i].size();
//                    std::cout << start_index << std::endl;
                    /*标记成功flag*/
                    successFlag = true;
                    continue;
                } else {
                    /*递归检查剩余的单词*/
                    bool ret = checkLast(start_index, s, wordDict);

                    start_index -= wordDict[i].size();
                    if (!ret) {

                        /*如果后续失败，那么就该将该位置和该单词插入小本本*/
//                        std::cout << start_index <<"插入"<< wordDict[i] << std::endl;
                        checkMap[start_index].insert(wordDict[i]);
                    }else{
                        successFlag=true;
                    }
                    continue;
                }
            } else {
                /*说明temp此时和字典中此单词不匹配，那么就该将该位置和该单词插入小本本，继续遍历字典*/
//                std::cout << start_index <<"插入"<< wordDict[i] << std::endl;
                checkMap[start_index].insert(wordDict[i]);
                continue;
            }
        }
/*
        std::cout << ".....@....." << std::endl;
        for (int i = 0; i != vs.size(); ++i) {
            std::cout << vs[i]<<" ";
        }
        std::cout << std::endl;

        std::cout << ".....@....." << std::endl;
*/

/*
        std::cout << "..........." << std::endl;
        for (int i = 0; i != s.size(); ++i) {
            auto sett = checkMap[i];
            for (const auto &item:sett) {
                std::cout << i << item << std::endl;
            }
        }
        std::cout << "..........." << std::endl;
*/

        /*说明遍历了所有，因此栈顶出栈*/
//        std::cout << "@@@@" << std::endl;
//        std::cout << vs.back() << std::endl;
        if (!vs.empty())
            vs.pop_back();
        /*if(successFlag==false){
            std::cout << "--------" << std::endl;

            for (const auto &item:vs) {
                std::cout << item << std::endl;
            }
            std::cout << "--------" << std::endl;
        }*/
        return successFlag;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        checkLast(0, std::move(s), wordDict);
        return ret;
    }
};

int main(int argc, char *argv[]) {

    Solution s;
    vector<string> wordDict{"aaaa", "aa", "a"};
//    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
    auto v = s.wordBreak("aaaaaaa", wordDict);
    std::cout << v.size() << std::endl;

    for (const auto &item:v) {
        std::cout << item << std::endl;
    }

    return 0;
}
/*
 * ["a a a a a a a"
 * ,"aa a a a a a"
 * ,"a aa a a a a"
 * ,"a a aa a a a"
 * ,"aa aa a a a"
 * ,"aaaa a a a"
 * ,"a a a aa a a"
 * ,"aa a aa a a"
 * ,"a aa aa a a"
 * ,"a aaaa a a",
 * "a a a a aa a",
 * "aa a a aa a"
 * ,"a aa a aa a"
 * ,"a a aa aa a"
 * ,"aa aa aa a"
 * ,"aaaa aa a"
 * ,"a a aaaa a"
 * ,"aa aaaa a",
 * "a a a a a aa"
 * ,"aa a a a aa"
 * ,"a aa a a aa",
 * "a a aa a aa",
 * "aa aa a aa",
 * "aaaa a aa"
 * ,"a a a aa aa",
 * "aa a aa aa",
 * "a aa aa aa",
 * "a aaaa aa",
 * "a a a aaaa"
 * ,"aa a aaaa",
 * "a aa aaaa"]*/