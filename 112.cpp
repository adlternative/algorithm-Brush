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
  bool dfs(TreeNode *root, int targetSum, int sum) {
    if (!root->left && !root->right) {
      if (sum == targetSum)
        return true;
    }

    if (root->left) {
      sum += root->left->val;
      if (dfs(root->left, targetSum, sum))
        return true;
      sum -= root->left->val;
    }
    if (root->right) {
      sum += root->right->val;
      if (dfs(root->right, targetSum,sum))
        return true;
      sum -= root->right->val;
    }
    return false;
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;
    return dfs(root, targetSum, root->val);
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
