//
// Created by adl on 2020/11/3.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    bool validMountainArray(vector<int> &A) {
        if (A.empty()) {
            return false;
        }

        int cur = 0;
        while (cur != A.size() - 1 && A[cur] < A[cur + 1]) {
            cur++;
        }
        if (cur == A.size() - 1 || cur == 0) {
            return false;
        }
        int temp = cur;
        while (temp != A.size() - 1 && A[temp] > A[temp + 1]) {
            temp++;
        }
        if (temp == A.size() - 1) {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> A{0, 3, 2, 1};
    auto a = s.validMountainArray(A);
    std::cout << a << std::endl;
    return 0;
}