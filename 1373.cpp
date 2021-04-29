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

class Solution {
public:
  long long Max;
  bool getBSTSumAndMaxAndMin(TreeNode *root, long long *max, long long *min,
                             long long *sum) {
    long long ret = 0;
    long long rightSum;
    long long leftSum;
    long long rightMax;
    long long leftMax;
    long long rightMin;
    long long leftMin;
    bool leftValid = false;
    bool rightValid = false;

    if (!root)
      return false;
    if (!root->left && !root->right) {
      *max = *min = *sum = root->val;
      Max = std::max(*sum, Max);
      // if (Max == 20)
      //   std::cout << "?" << root->val << std::endl;
      return true;
    } else if (root->left && !root->right) {
      leftValid =
          getBSTSumAndMaxAndMin(root->left, &leftMax, &leftMin, &leftSum);
      if (!leftValid || root->val <= leftMax)
        return false;
      *max = root->val;
      *min = leftMin;
      Max = std::max(leftSum, Max);
      // if (Max == 20)
      //   std::cout << "!" << root->val << std::endl;

      *sum = root->val + leftSum;
      Max = std::max(*sum, Max);
      // if (Max == 20)
      //   std::cout << "!" << root->val << std::endl;

      return true;
    } else if (!root->left && root->right) {
      rightValid =
          getBSTSumAndMaxAndMin(root->right, &rightMax, &rightMin, &rightSum);
      if (!rightValid || root->val >= rightMin)
        return false;
      *min = root->val;
      *max = rightMax;
      Max = std::max(rightSum, Max);
      // if (Max == 20)
      //   std::cout << "#" << root->val << std::endl;
      *sum = root->val + rightSum;
      Max = std::max(*sum, Max);
      // if (Max == 20)
        // std::cout << "((" << root->val << "&&" << rightSum << "^^" << rightMin
        //           << std::endl;

      return true;
    } else { /* 最后是看两边 */
      leftValid =
          getBSTSumAndMaxAndMin(root->left, &leftMax, &leftMin, &leftSum);
      rightValid =
          getBSTSumAndMaxAndMin(root->right, &rightMax, &rightMin, &rightSum);

      if (!leftValid || root->val <= leftMax)
        return false;
      if (!rightValid || root->val >= rightMin)
        return false;
      Max = std::max(rightSum, Max);
      Max = std::max(leftSum, Max);
      // if (Max == 20)
      //   std::cout << "%" << root->val << std::endl;
      *sum = root->val + leftSum + rightSum;
      Max = std::max(*sum, Max);
      // if (Max == 20)
      //   std::cout << "&&" << root->val << std::endl;
      *max = rightMax;
      *min = leftMin;
      return true;
    }
    return false;
  }
  long long maxSumBST(TreeNode *root) {
    long long max, min, sum;
    bool valid;
    Max = LONG_MIN;

    if (!root)
      return 0;
    getBSTSumAndMaxAndMin(root, &max, &min, &sum);

    return std::max(Max, (long long)0);
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v{0,  2,       9,       INT_MIN, INT_MIN, 8, 1,
                -1, INT_MIN, INT_MIN, 4,       -5,      2, INT_MIN,
                1,  INT_MIN, -3,      1,       3,       3, 0};
  /*
                        0
                2                       9
            x         x         8             1
                          -1     X        X      4
                        -5  2                 X    1
                      X -3  1 3                   3  0


   */

  /*
    [4,8,null,6,1,9,null,-5,4,null,null,null,-3,null,10]
             4
        8       x
    6        1
  9  x   -5   4
x x    x -3  x 10

  */

  TreeNode *root = TreeNode::bulid(v);
  root->inOrder();
  Solution s;
  auto ret = s.maxSumBST(root);
  // std::cout << ret << std::endl;
  return 0;
}
