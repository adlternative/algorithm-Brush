//
// Created by adl on 2020/12/4.
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

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> tQueue;
        set<TreeNode *> tSet;
        tSet.insert(root);
        tQueue.push(root);
        int depth = 1;
        while (!tQueue.empty()) {
            int size = tQueue.size();
            /*这时候需要将此时队列遍历一遍，因为这些节点是同一层的，这样我才有理由depth++*/
            for (int i = 0; i < size; i++) {
                auto cur = tQueue.front();
                tQueue.pop();
                if (!cur->right && !cur->left) {
                    return depth;
                }
                if (cur->left != nullptr)tQueue.push(cur->left);
                if (cur->right != nullptr)tQueue.push(cur->right);
            }
            depth++;

        }
        return depth;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto root = new TreeNode(3);
    auto l1 = new TreeNode(9);
    auto r1 = new TreeNode(20);
    root->left = l1;
    root->right = r1;
    auto rl1 = new TreeNode(15);
    auto rr1 = new TreeNode(7);
    r1->left = rl1;
    r1->right = rr1;
    int dp = s.minDepth(root);
    std::cout << dp << std::endl;

    return 0;
}