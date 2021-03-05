//
// Created by adl on 2020/9/14.
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

class Solution {
public:
    stack<TreeNode *> s;

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;

        auto cur = root;//1
        s.push(cur);
        while (!s.empty()) {
            /*左全进*/
            while (cur->left) {
                s.push(cur->left);//s 1
                cur = cur->left;
            }
            /*站顶*/
            auto t = s.top();// t 1
            s.pop();
            v.push_back(t->val);

            if (t->right) {//2
                cur = t->right;
                s.push(cur);
            }
//            cur = t->right;
        }
        //        s.pop();
        return v;
    }
};


int main(int argc, char *argv[]) {

    TreeNode *tt[3];
    for (int i = 0; i != 3; ++i) {
        tt[i] = new TreeNode(i + 1);
    }
    tt[0]->right = tt[1];
    tt[1]->left = tt[2];
    Solution ss;
    auto v = ss.inorderTraversal(tt[0]);
    for (const auto &item:v) {
        std::cout << item << std::endl;
    }
    return 0;
}