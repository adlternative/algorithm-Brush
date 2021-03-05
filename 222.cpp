//
// Created by adl on 2020/11/24.
//

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution() : cnt(0) {}

    int cnt;

    int countNodes(TreeNode *root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    auto ret = s.countNodes(t1);
    std::cout << ret << std::endl;

    return 0;
}