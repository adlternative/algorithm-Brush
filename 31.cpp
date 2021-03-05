//
// Created by adl on 2　2　/11/1　.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        /*
        124563 ->124536
        35421 ->  4 1235
        35412 ->  3 5 4 21
        142 ->214
        54321 ->sort
        123465 ->123456
         */

        int size = nums.size();//5
        int i = size - 1;
        for (; i != 0; --i) {
            if (nums[i] > nums[i - 1]) {
                break;
            }
        }
        if (i != 0) {
            int min = nums[i];
            int key = i;

            for (int j = i; j != size; j++) {
                if (nums[j] < min && nums[j] > nums[i - 1]) {
                    min = nums[j];
                    key = j;
                }
            }
            swap(nums[i - 1], nums[key]);
        }
        sort(nums.begin() + i, nums.end());
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{2,3,1};
    s.nextPermutation(v);

    for (const auto &item:v) {
        std::cout << item << std::endl;
    }
    return 0;
}