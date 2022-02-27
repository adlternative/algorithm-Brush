#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
    if (!root)
      return false;

    if (target == root)
      return true;

    if (root->left) {
      path.push_back(root->left);
      if (dfs(root->left, target, path))
        return true;
      path.pop_back();
    }

    if (root->right) {
      path.push_back(root->right);
      if (dfs(root->right, target, path))
        return true;
      path.pop_back();
    }

    return false;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    vector<TreeNode *> p_path;
    vector<TreeNode *> q_path;

    p_path.push_back(root);
    dfs(root, p, p_path);

    q_path.push_back(root);
    dfs(root, q, q_path);

    int size1 = p_path.size();
    int size2 = q_path.size();
    for (int i = 0; i < min(size1, size2); i++) {
      if (p_path[i] != q_path[i])
        return p_path[i - 1];
    }
    return nullptr;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
