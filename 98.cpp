#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void Inorder(TreeNode *root, const function<void(TreeNode *)> &fn) {
  if (!root)
    return;
  Inorder(root->left, fn);
  fn(root);
  Inorder(root->right, fn);
}

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    bool flag = true;
    bool start = false;
    int cur;
    auto fn = [&](TreeNode *node) {
      if (!start) {
        start = true;
      } else if (node->val <= cur) {
        flag = false;
      }
      cur = node->val;
    };
    Inorder(root, fn);
    return flag;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
