//
// Created by adl on 2020/11/24.
//

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 *              1
 *        2           3
 *    4     7      5     6
 * 8   9
 * */
class Solution {
public:

    int ret = INT_MIN;

    int maxDevotion(TreeNode *root) {
        if (!root)return 0;
        int left = max(0, maxDevotion(root->left));
        int right = max(0, maxDevotion(root->right));
        ret = max(ret, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode *root) {
        maxDevotion(root);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto l = new TreeNode(2);
    auto r = new TreeNode(3);
    auto root = new TreeNode(1, l, r);
    int ret = s.maxPathSum(root);
    std::cout << ret << std::endl;

    return 0;
}