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

void help(TreeNode *root, const function<void(TreeNode *)> &fn) {
  if (!root)
    return;
  help(root->left, fn);
  help(root->right, fn);
  fn(root);
}

class Solution {
public:
  unordered_map<TreeNode *, long long> node2sum;
  long long max_sum = 0;
  long long total_sum = 0;

  int maxProduct(TreeNode *root) {
    auto calculateSum = [&](TreeNode *node) -> void { total_sum += node->val; };
    auto helpMaxProduct = [&](TreeNode *cur) -> void {
      long long sum = cur->val;
      if (cur->left)
        sum += node2sum[cur->left];
      if (cur->right)
        sum += node2sum[cur->right];
      if (std::abs(sum * 2 - total_sum) < std::abs(max_sum * 2 - total_sum))
        max_sum = sum;
      node2sum[cur] = sum;
    };
    help(root, calculateSum);
    help(root, helpMaxProduct);

    return (int)((max_sum * (total_sum - max_sum)) % (1000000000 + 7));
  }
};
TEST(Solution, isMatch) {
  Solution s;
  auto root = new TreeNode(
      1, nullptr,
      new TreeNode(2, new TreeNode(3),
                   new TreeNode(4, new TreeNode(5), new TreeNode(6))));
  EXPECT_EQ(s.maxProduct(root), 90);
  auto deleteNode = [&](TreeNode *root) { delete root; };
  help(root, deleteNode);
}
