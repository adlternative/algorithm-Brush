//
// Created by adl on 2020/10/27.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int>results(nums.size());

        for (int i = 0; i != nums.size()-1; ++i) {
            for (int j = i+1; j != nums.size(); ++j) {
                auto tmp_j =nums[j];
                auto tmp_i=nums[i];
                if (tmp_i >tmp_j ) {
                    results[i]++;
                } else if (tmp_i<tmp_j){
                    results[j]++;
                }
            }
        }
        return results;
    }
};


int main(int argc, char *argv[]) {
    return 0;
}
