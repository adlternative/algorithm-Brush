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
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return 1;

    int max_len = 0;
    map<TreeNode *, int> node2idx;
    deque<TreeNode *> nodes;

    nodes.push_back(root);
    node2idx[root] = 0;
    while (nodes.size()) {
      int lens = nodes.size();
      int begin_index;
      int end_index;

      // node2idx
      for (int i = 0; i < lens; i++) {
        auto cur = nodes.front();
        if (i == 0)
          begin_index = node2idx[cur];
        if (i == lens - 1)
          end_index = node2idx[cur];
        nodes.pop_front();

        if (cur->left) {
          nodes.push_back(cur->left);
          node2idx[cur->left] = node2idx[cur] * 2 + 1;
        }
        if (cur->right) {
          nodes.push_back(cur->right);
          node2idx[cur->right] = node2idx[cur] * 2 + 2;
        }
      }
      if (end_index - begin_index + 1 > max_len)
        max_len = end_index - begin_index + 1;
    }
    return max_len;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
