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

void PostFixTraversal(TreeNode *node,
                      const std::function<void(TreeNode *)> &fn) {
  if (!node)
    return;

  PostFixTraversal(node->left, fn);
  PostFixTraversal(node->right, fn);
  fn(node);
}

class Solution {
public:
  void flatten(TreeNode *root) {
    auto fn = [](TreeNode *node) {
      if (!node->left)
        return;

      auto right = node->right;
      node->right = node->left;
      auto cur = node;
      while (cur->right) {
        cur = cur->right;
      }
      cur->right = right;
      node->left = nullptr;
    };

    PostFixTraversal(root, fn);
  }
};

TEST(Solution, isMatch) {
  Solution s;
  TreeNode *nodes = new TreeNode[6];
  nodes[0].val = 1;
  nodes[1].val = 2;
  nodes[2].val = 5;
  nodes[3].val = 3;
  nodes[4].val = 4;
  nodes[5].val = 6;

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];

  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];

  nodes[2].right = &nodes[5];

  s.flatten(&nodes[0]);
  // EXPECT_EQ(s.(), );

  delete[] nodes;
}
