#include <cstdio>
#include <limits.h>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  static TreeNode *bulid(const vector<int> &v) {
    TreeNode *root = nullptr;
    auto len = v.size();
    vector<TreeNode *> vtn(len);

    for (size_t i = 0; i < len; i++) {
      TreeNode *node = nullptr;
      int val = v[i];

      if (val != INT_MIN) {
        node = new TreeNode(val);
        vtn[i] = node;
        if (i == 0) {
          root = node;
          continue;
        }
      }
      if (i % 2 && vtn[i / 2])
        vtn[i / 2]->left = node;
      else if (vtn[(i - 1) / 2])
        vtn[(i - 1) / 2]->right = node;
    }
    return root;
  }
  void inOrder() {
    if (left)
      left->inOrder();
    printf("%d ", val);
    if (right)
      right->inOrder();
  }
};
