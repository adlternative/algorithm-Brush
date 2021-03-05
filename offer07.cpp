#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
/*


前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

前序 第一个9作为树根 接着一直向左走
肯定会有一个和前序遍历相同的元素

,20,15,7
,3,15,20,7

 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  void print() {
    printf("%d\n", val);
    if (left)
      left->print();
    if (right)
      right->print();
  }
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0)
      return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
      return root;

    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int i = 0;
    while (inorder[i] != root->val) {
      i++;
    }
    /* 找到中序遍历中root的位置i */
    /* 然后i之前0~i-1都是左树 */
    /* 然后i之后i+1~...都是右树 */
    // printf("%d %d\n", inorder[0], inorder[i]);
    vector<int> subLeftInOrder(inorder.begin(), inorder.begin() + i);
    vector<int> subLeftPreOrder(preorder.begin() + 1,
                                preorder.begin() + 1 + subLeftInOrder.size());
    // for (auto i : subLeftInOrder) {
    //   printf("l1=%d\n", i);
    // }
    // for (auto i : subLeftPreOrder) {
    //   printf("l2=%d\n", i);
    // }
    // printf("%d %d\n", inorder[i+1], inorder[i]);

    vector<int> subRightInOrder(inorder.begin() + i + 1, inorder.end());
    vector<int> subRightPreOrder(preorder.begin() + 1 + subLeftInOrder.size(),
                                 preorder.end());
    // for (auto i : subRightInOrder) {
    //   printf("r1=%d\n", i);
    // }
    // for (auto i : subRightInOrder) {
    //   printf("r2=%d\n", i);
    // }
    if (!subLeftPreOrder.empty()) {
      left = buildTree(subLeftPreOrder, subLeftInOrder);
    } else {
      // printf("l=%p", left);
    }
    if (!subRightPreOrder.empty())
      right = buildTree(subRightPreOrder, subRightInOrder);
    // } else {
    //   printf("r=%p", right);
    // }
    root->left = left;
    root->right = right;
    return root;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  vector<int> p = {1, 2};
  vector<int> i = {1, 2};
  Solution s;
  auto r = s.buildTree(p, i);
  r->print();
  // if (!r)
  //   std::cout << "1" << std::endl;
  return 0;
}
