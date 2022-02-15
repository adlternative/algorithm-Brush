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
  TreeNode *buildTreeHelp(vector<int> &inorder, int begin, int end,
                          vector<int> &postorder, int index) {
    int len = end - begin;
    if (len <= 0)
      return nullptr;

    int v = postorder[index];
    auto root = new TreeNode(v);
    if (len == 1)
      return root;

    int i = begin;
    for (; i < end; i++)
      if (inorder[i] == v)
        break;

    root->left = buildTreeHelp(inorder, begin, i, postorder,
                               index - (end - (i + 1)) - 1);
    root->right = buildTreeHelp(inorder, i + 1, end, postorder, index - 1);
    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int lens;
    lens = inorder.size();
    int v = postorder[lens - 1];
    auto root = new TreeNode(v);
    int i = 0;
    for (; i < lens; i++)
      if (inorder[i] == v)
        break;

    root->left = buildTreeHelp(inorder, 0, i, postorder,
                               lens - 1 - (lens - (i + 1)) - 1);
    root->right = buildTreeHelp(inorder, i + 1, lens, postorder, lens - 1 - 1);

    return root;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
