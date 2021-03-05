//
// Created by adl on 2020/12/3.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;

    void dfs(vector<int> &item, vector<int> &nums) {
        if (item.size() == nums.size()) {
            ret.push_back(item);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if(find(item.begin(), item.end(),nums[i])!=item.end()) {
                continue;
            }
            item.push_back(nums[i]);
            dfs(item, nums);
            item.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> vv;
        dfs(vv, nums);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v{1, 2, 3};
    auto vv = s.permute(v);
    for (const auto &item:vv) {
        for (const auto &i:item) {
            std::cout << i << " ";
        }
        printf("\n");
    }
    return 0;
}