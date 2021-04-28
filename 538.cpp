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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/* 首先我们的r最大 r->v=r->v
r->p 第二  r->p->v+=r->v
r->p->p 第三  r->p->p->v+=r->p->v
r->p->p->l 第四  r->p->p->l+=r->p->p
也就是说反着中序遍历 加上其前一个点算出的新值

 */
class Solution {
public:
  // stack<TreeNode *> prevStk;
  TreeNode *prev = nullptr;
  TreeNode *convertBST(TreeNode *root) {
    if (!root)
      return root;
    if (root->right) {
      convertBST(root->right);
    }
    if (prev) {
      root->val += prev->val;
    }
    prev = root;
    if (root->left) {
      convertBST(root->left);
    }
    return root;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // vector<>
  // [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
  TreeNode *root;

  auto ret = s.convertBST(root);

  return 0;
}
