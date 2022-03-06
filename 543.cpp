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
  int maxLen = 0;

  int getHeight(TreeNode *root) {
    if (!root)
      return 0;
    int lh, rh;
    lh = root->left ? getHeight(root->left) : 0;
    rh = root->right ? getHeight(root->right) : 0;

    maxLen = max(maxLen, lh + rh);
    return max(lh, rh) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    getHeight(root);
    return maxLen;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
