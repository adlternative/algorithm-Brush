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

class Solution {
public:
  void preorderTraversal(TreeNode *node, const function<void(TreeNode *)> &fn) {
    if (!node)
      return;
    fn(node);
    preorderTraversal(node->left, fn);
    preorderTraversal(node->right, fn);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    auto fn = [&](TreeNode *node) { ret.push_back(node->val); };
    preorderTraversal(root, fn);
    return ret;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
