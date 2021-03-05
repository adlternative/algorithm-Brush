//
// Created by adl on 2020/10/27.
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
private:
    stack<TreeNode *> s;
    vector<int> v;
public:
    vector<int> preorderTraversal(TreeNode *root) {
//中左右
/*
    　１
　　２　　3
　4　5　6　７

 1 2 4 5 3 6 7
    3 5 4
    1 2

 */
        if (!root){
            return v;
        }
        s.push(root);
        while (!s.empty()) {
            auto top = s.top();
            s.pop();
            if (top->right)
                s.push(top->right);
            if (top->left)
                s.push(top->left);
            v.push_back(top->val);
        }

        return v;
    }
};


int main(int argc, char *argv[]) {

    return 0;
}
