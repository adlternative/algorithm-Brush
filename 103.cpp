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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (!root) [[unlikely]]
      return ret;
    deque<TreeNode *> node_queue;

    node_queue.push_back(root);
    bool reverse = false;

    while (!node_queue.empty()) {
      int len = node_queue.size();
      vector<int> v;
      for (int i = 0; i < len; i++) {
        auto cur_node = node_queue.front();
        node_queue.pop_front();
        if (reverse) {
          v.insert(v.begin(), cur_node->val);
        } else {
          v.push_back(cur_node->val);
        }
        if (cur_node->left)
          node_queue.push_back(cur_node->left);
        if (cur_node->right)
          node_queue.push_back(cur_node->right);
      }
      ret.push_back(std::move(v));
      reverse = !reverse;
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  auto ret = s.zigzagLevelOrder(new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  for (auto &v : ret) {
    for (auto &i : v)
      std::cout << i;
    std::cout << std::endl;
  }
}
