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
  bool isCompleteTree(TreeNode *root) {
    unordered_map<TreeNode *, int> node2idx;
    queue<TreeNode *> node_queue;
    node_queue.push(root);
    node2idx.emplace(root, 0);

    int index = 1;
    /* 层序遍历 */
    while (!node_queue.empty()) {
      auto top_node = node_queue.front();
      node_queue.pop();
      auto idx = node2idx[top_node];

      if (top_node->left) {
        if (index != idx * 2 + 1)
          return false;
        node_queue.push(top_node->left);
        node2idx.emplace(top_node->left, index++);
      }

      if (top_node->right) {
        if (index != idx * 2 + 2)
          return false;
        node_queue.push(top_node->right);
        node2idx.emplace(top_node->right, index++);
      }
    }
    return true;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  // new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)))
  // EXPECT_EQ(s.isCompleteTree(), );
}
