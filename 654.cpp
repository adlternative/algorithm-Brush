#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
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

class Solution {
  size_t findMax(vector<int> &nums, int b, int e) {
    size_t pos = -1;
    int max_ = INT_MIN;
    for (size_t i = b; i < e; i++) {
      if (max_ <= nums[i]) {
        max_ = nums[i];
        pos = i;
      }
    }
    return pos;
  }
  TreeNode *buildTree(vector<int> &nums, int b, int e) {
    if (b == e)
      return nullptr;
    size_t pos = findMax(nums, b, e);
    if (pos == -1)
      return nullptr;
    TreeNode *root = new TreeNode(nums[pos]);
    root->right = buildTree(nums, pos + 1, e);
    root->left = buildTree(nums, b, pos);
    return root;
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    size_t len = nums.size();
    if (len == 0)
      return nullptr;
    size_t pos = findMax(nums, 0, len);
    if (pos == -1)
      return nullptr;
    TreeNode *root = new TreeNode(nums[pos]);
    root->right = buildTree(nums, pos + 1, len);
    root->left = buildTree(nums, 0, pos);
    return root;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{3, 2, 1, 6, 0, 5};
  auto root = s.constructMaximumBinaryTree(v);
  if (root)
    std::cout << root->val << std::endl;

  return 0;
}
