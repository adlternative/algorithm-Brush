//
// Created by adl on 2020/12/1.
//

#include<bits/stdc++.h>

#include <utility>

using namespace std;


/*
 *需求一个容器类,内含有个n元素的序列,每一个子元素可以是int,string,序列,
 **/
class Vec;

class Data {
public:
    void *data;
};

class Vec : public Data {
public:
    vector<Data *> vData;
};

class Solution {
public:
    enum Stat {
        DEAL_LEFT_MID,/*处理左括号*/
        DEAL_RIGHT_MID,/*处理右括号*/
        DEAL_INT,/*处理整数*/
        DEAL_STRING,
    };
    Stat stat;


    Solution(string &&ss) : vecRoot(nullptr), s(std::move(ss)), curIndex(0) {}

    string s;
    int curIndex;
    Vec *vecRoot;
    Vec *curNode;

    Vec *getVec() {
        if (s[curIndex] == ']') {
            stat = DEAL_RIGHT_MID;
            return curNode;
        } else if (s[curIndex] == ',') {

        } else if (s[curIndex] >= '0' || s[curIndex] <= '9') {

        }
    }

    void method() {
        int size = s.size();
        for (int i = 0; i != size; ++i) {
            switch (s[i]) {
                case '[': {
                    if (!vecRoot) {
                        vecRoot = new Vec;
                        curNode = vecRoot;
                    } else {
                        auto newVec = new Vec;
                        Data *data = new Data;
                        data->data = (void *) newVec;
                        curNode->vData.push_back(data);

                        /*...*/
                    }
                    stat = DEAL_LEFT_MID;
                    break;
                }
                case ']': {

                    stat = DEAL_RIGHT_MID;

                    break;
                }
                case ',':
                    /*push_back*/
                    break;
            }
        }

    }

};

int main(int argc, char *argv[]) {
//    Solution s;
//    s.method("[1,[3,4,[2,5],3],4]");

    vector<any> va;
    any a1 = 1;
    any a2 = string("string");
    va.push_back(a1);
    va.push_back(a2);
    for (const auto &item:va) {
        if (item.type() == typeid(std::string)) {
            std::cout << std::any_cast<string>(item) << std::endl;
        }
        if (item.type() == typeid(int)) {
            std::cout << std::any_cast<int>(item) << std::endl;
        }
    }
    //    for (int i = 0; i != va.size(); ++i) {

//    std::cout << std::any_cast<int>(va[0]) << std::endl;
//    std::cout << std::any_cast<string>(va[1]) << std::endl;

//    const auto& s = std::make_any<std::string>("hello");
//
//    if (s.type() == typeid(std::string))//删除顶层cosnt和引用后的类型
//    {
//        auto a = std::any_cast<std::string>(s);
//        std::cout << a << std::endl;
//    }

//        std::cout << va[i].get() << std::endl;
//
//    }
    return 0;
}