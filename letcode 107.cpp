//
// Created by adl on 2020/9/6.
//
#include<bits/stdc++.h>

using namespace std;

/*
int main(int argc,char*argv[])
{
    return 0;
}
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> vec;
        TreeNode *cur = root;
        queue<TreeNode *> lt;
        lt.push(root);

        while (!lt.empty()) {
            vector<int>sub;
            for (int i = 0; i != lt.size(); ++i) {
                auto node = lt.front();
                lt.pop();
                if (cur->left)
                    lt.push(node->left);
                if (cur->right)
                    lt.push(node->right);
                sub.push_back(node->val);
            }
            vec.push_back(sub);
        }
        return vec;
    }
};