//
// Created by adl on 2020/9/17.
//

#include<bits/stdc++.h>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void changelr(TreeNode *t) {
        std::swap(t->left, t->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        do{
            if(!root){
                break;
            }
            changelr(root);
            if (root->right)
                invertTree(root->right);
            if (root->left)
                invertTree(root->left);
        }while(0);
        return root;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}