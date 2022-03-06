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

// void Inorder(TreeNode *root, const function<void(TreeNode *)> &fn) {
//   Inorder(root->left, fn);
//   fn(root);
//   Inorder(root->right, fn);
// }

class Solution {
public:
  bool Check(TreeNode *left, TreeNode *right) {
    if (!left && !right)
      return true;
    else if (left && right && left->val == right->val)
      return Check(left->left, right->right) && Check(left->right, right->left);
    else
      return false;
  }

  bool isSymmetric(TreeNode *root) {
    return root ? Check(root->left, root->right) : true;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
