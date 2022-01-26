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

void InOrderTraversal(TreeNode *node,
                      const std::function<void(TreeNode *)> &fn) {
  if (node->left)
    InOrderTraversal(node->left, fn);
  fn(node);
  if (node->right)
    InOrderTraversal(node->right, fn);
}

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int ret;
    auto count_fn = [&](TreeNode *node) {
      if (!--k)
        ret = node->val;
    };
    InOrderTraversal(root, count_fn);
    return ret;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
