//
// Created by adl on 2020/11/27.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int cnt = 0;
        int N = A.size();
        unordered_map<int, int> Mab;
        unordered_map<int, int> Mcd;
        for (int i = 0; i != N; i++) {
            for (int j = 0; j != N; ++j) {
                auto iter = Mab.find(A[i] + B[j]);
                if (iter == Mab.end())
                    Mab.insert({A[i] + B[j], 1});
                else
                    iter->second++;
            }

        }
//        for (const auto &item:Mab) {
//            std::cout << item.first<<" " ;
//            std::cout << item.second << std::endl;
//        }

        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                auto iter = Mab.find(-(C[i] + D[j]));
                if (iter != Mab.end()){
                    cnt+=iter->second;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> A = {-1, -1};//2
    vector<int> B = {-1, 1};
    vector<int> C = {-1, 1};
    vector<int> D = {1, -1};
    std::cout << s.fourSumCount(A, B, C, D) << std::endl;

    return 0;
}