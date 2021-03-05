//
// Created by adl on 2020/8/15.
//

#include<bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ve;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true) {
            while (node->left) {
                st.push(node);
                node = node->left;
            }
            ve.push_back(node->val);
            ve.push_back(st.top()->val);
            node=st.top()->right;
            if(!node){
                break;
            }
        }
        return ve;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}