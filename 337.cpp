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
  unordered_map<TreeNode *, int> mem;
  int maxVal(TreeNode *root) {
    if (!root)
      return 0;

    auto iter = mem.find(root);
    if (iter != mem.end())
      return iter->second;

    int choice_max_val = 0, un_choice_max_val = 0;
    choice_max_val += root->val;
    if (root->left) {
      choice_max_val += maxVal(root->left->left) + maxVal(root->left->right);
    }
    if (root->right) {
      choice_max_val += maxVal(root->right->left) + maxVal(root->right->right);
    }
    un_choice_max_val += maxVal(root->left) + maxVal(root->right);
    return max(choice_max_val, un_choice_max_val);
  }
  int rob(TreeNode *root) { return maxVal(root); }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
