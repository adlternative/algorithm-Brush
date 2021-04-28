#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  void inOrder() {
    if (left)
      left->inOrder();
    printf("%d ", val);
    if (right)
      right->inOrder();
  }
};

class Solution {
public:
  void inOrder(TreeNode *root, function<void(TreeNode *)> &f) {
    if (!root)
      return;
    if (root->left)
      inOrder(root->left, f);
    f(root);
    if (root->right)
      inOrder(root->right, f);
  }
  /* 0 2 mid=1 */
  TreeNode *buildTree(vector<TreeNode *> &inOrderVec, int beg, int end) {
    TreeNode *ret;
    int mid = (beg + end) / 2; // 0
    ret = inOrderVec[mid];     // ret= v[0]
    if (beg == end) {
      ret->right = ret->left = nullptr;
      return ret;
    }

    if (beg + 1 <= mid)                                /* 0!=0 */
      ret->left = buildTree(inOrderVec, beg, mid - 1); /* [0,len/2) */
    else
      ret->left = nullptr;

    if (end >= mid + 1) /* 1!=0                0   1 */
      ret->right = buildTree(inOrderVec, mid + 1, end); /* [len/2+1,len) */
    else
      ret->right = nullptr;

    return ret;
  }
  TreeNode *balanceBST(TreeNode *root) {
    TreeNode *ret;
    vector<TreeNode *> inOrderVec;
    function<void(TreeNode *)> func = [&](TreeNode *node) -> void {
      inOrderVec.push_back(node);
    };
    inOrder(root, func); /* 有序放入vec中 */
    size_t len = inOrderVec.size();
    ret = inOrderVec[len / 2];                           // 4/2=2
    if (1 <= len / 2)                                    //
      ret->left = buildTree(inOrderVec, 0, len / 2 - 1); /* [0,len/2-1] */
    else
      ret->left = nullptr;
    if (len - 1 >= len / 2 + 1) {
      ret->right =
          buildTree(inOrderVec, len / 2 + 1, len - 1); /* [len/2+1,len-1] */
    } else
      ret->right = nullptr;
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<TreeNode *> vt;
  for (size_t i = 0; i < 4; i++) {
    vt.push_back(new TreeNode(i));
  }
  for (size_t i = 0; i < 4; i++)
    if (i != 4)
      vt[i]->right = vt[i + 1];

  auto ret = s.balanceBST(vt[0]);
  ret->inOrder();
  return 0;
}
