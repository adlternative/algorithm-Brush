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

// void PostOrder(TreeNode *node, const function<void(TreeNode *)> &fn) {
//   if (!node)
//     return;
//   PostOrder(node->left, fn);
//   PostOrder(node->right, fn);
//   fn(node);
// }

class Solution {
public:
  bool getHeight(TreeNode *node, int &height) {
    if (!node) {
      height = 0;
      return true;
    }

    int lh, rh;
    if (!getHeight(node->left, lh))
      return false;
    if (!getHeight(node->right, rh))
      return false;

    if (lh > rh + 1 || rh > lh + 1)
      return false;
    height = max(lh, rh) + 1;
    return true;
  }
  bool isBalanced(TreeNode *root) {
    int _;
    return getHeight(root, _);
  }
};
TEST(Solution, isMatch) {
  Solution s;
  TreeNode *nodes = new TreeNode[5];
  vector<int> val = {3, 9, 20, 15, 7};
  for (int i = 0; i++; i++) {
    nodes[i].val = val[i];
  }
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[2].left = &nodes[3];
  nodes[2].right = &nodes[4];

  EXPECT_EQ(s.isBalanced(&nodes[0]), true);
  delete[] nodes;
}
