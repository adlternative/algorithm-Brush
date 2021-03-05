#include <bits/stdc++.h>
#include <ell/util.h>
#include <errno.h>
using namespace std;

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
  int cnt;
  int sum_;
  Solution() : cnt(0) {}
  void passVec(TreeNode *root, const vector<int> &v) {

    int addValue;
    valueMap[root].push_back(root->val);
    for (auto &&i : v) {
      addValue = i + root->val;
      if (addValue == sum_) {
        cnt++;
      }
      valueMap[root].push_back(addValue);
    }
    if (root->val == sum_)
      ++cnt;
    if (root->left)
      passVec(root->left, valueMap[root]);
    if (root->right)
      passVec(root->right, valueMap[root]);
  }
  /* 每个节点关联一个vector<int> */
  map<TreeNode *, vector<int>> valueMap;
  int pathSum(TreeNode *root, int sum) {
    if (!root)
      return 0;
    sum_ = sum;
    valueMap[root].push_back(root->val);
    if (root->val == sum)
      ++cnt;
    if (root->left)
      passVec(root->left, valueMap[root]);
    if (root->right)
      passVec(root->right, valueMap[root]);
    return cnt;
  }
};
