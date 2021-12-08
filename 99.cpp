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
void InOrderTraversal(TreeNode *node, std::function<void(TreeNode *)> fn) {
  if (node->left)
    InOrderTraversal(node->left, fn);
  fn(node);
  if (node->right)
    InOrderTraversal(node->right, fn);
}
/*
1234567
1[73]45[62]
[72]345[61]

 */
class Solution {
public:
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> nodes;
    InOrderTraversal(root, [&](TreeNode *node) { nodes.push_back(node); });
    auto len = nodes.size();
    vector<int> poss;
    for (int i = 0; i < len - 1; i++) {
      if (nodes[i]->val > nodes[i + 1]->val) {
        poss.push_back(i);
      }
    }

    len = poss.size();
    if (len == 2) {
      swap(nodes[poss[0]]->val, nodes[poss[1] + 1]->val);
    } else if (len == 1) {
      swap(nodes[poss[0]]->val, nodes[poss[0] + 1]->val);
    }
  }
};

TEST(Solution, isMatch) {
  Solution s;

  std::cout << "\n***" << std::endl;
  TreeNode *root =
      new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
  std::cout << "\n***" << std::endl;
  s.recoverTree(root);
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
}

TEST(Solution, isMatch2) {
  Solution s;
  std::cout << "\n***" << std::endl;

  TreeNode *root = new TreeNode(3, new TreeNode(1),
                                new TreeNode(4, new TreeNode(2), nullptr));
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
  std::cout << "\n***" << std::endl;
  s.recoverTree(root);
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
}

TEST(Solution, isMatch3) {
  Solution s;

  std::cout << "\n***" << std::endl;
  TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
  std::cout << "\n***" << std::endl;
  s.recoverTree(root);
  InOrderTraversal(root,
                    [&](TreeNode *node) { std::cout << node->val << " "; });
}