//
// Created by adl on 2020/11/12.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> o1;
    vector<int> o2;

    vector<int> sortArrayByParityII(vector<int> &A) {
        vector<int> ret;
        for (const auto &item:A) {
            if (item % 2) {
                o2.push_back(item);
            } else {
                o1.push_back(item);
            }
        }
        int size = o1.size();
        for (int i = 0; i != size; ++i) {
            ret.push_back(o1[i]);
            ret.push_back(o2[i]);
        }
        return ret;
        /*奇数
         * 偶数*/
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int>v{4,2,5,7};
    auto a=s.sortArrayByParityII(v);
    for (const auto &item:a) {
        std::cout << item << std::endl;
    }

    return 0;
}