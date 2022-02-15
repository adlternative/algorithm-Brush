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
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode dummy(0, root, nullptr);
    auto cur = root;
    auto parent = &dummy;
    while (cur) {
      auto tmp = cur;
      if (cur->val > key)
        cur = cur->left;
      else if (cur->val < key)
        cur = cur->right;
      else
        break;
      parent = tmp;
    }

    if (cur) {
      if (!cur->right) {
        if (cur == parent->left) {
          parent->left = cur->left;
        } else {
          parent->right = cur->left;
        }
      } else {
        if (cur == parent->left) {
          parent->left = cur->right;
        } else {
          parent->right = cur->right;
        }
        if (cur->left) {
          auto c = cur->left;
          TreeNode *p;
          while (c) {
            p = c;
            c = c->right;
          }
          p->right = cur->right->left;
          cur->right->left = cur->left;
        }
      }
    }

    return dummy.left;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
