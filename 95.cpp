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
  void Print() {
    printf("root: %d", val);
    print();
    printf("\n");
  }

private:
  void print() {
    if (left)
      left->print();
    else
      printf("null ");
    printf("%d ", val);
    if (right)
      right->print();
    else
      printf("null ");
  }
};

class Solution {
public:
  vector<TreeNode *> helper(int start, int end) {
    vector<TreeNode *> ret;
    if (start == end) {
      return ret;
    }

    for (int i = start; i < end; ++i) {
      /* i 作为根 */
      auto &&left = helper(start, i);
      auto &&right = helper(i + 1, end);
      if (left.size() && right.size()) {
        for (auto lnode : left) {
          for (auto rnode : right) {
            TreeNode *node = new TreeNode(i + 1, lnode, rnode);
            ret.push_back(node);
          }
        }
      } else if (left.size()) {
        for (auto lnode : left) {
          TreeNode *node = new TreeNode(i + 1, lnode, nullptr);
          ret.push_back(node);
        }

      } else if (right.size()) {

        for (auto rnode : right) {
          TreeNode *node = new TreeNode(i + 1, nullptr, rnode);
          ret.push_back(node);
        }

      } else {
        TreeNode *node = new TreeNode(i + 1);
        ret.push_back(node);
      }
    }
    return ret;
  }
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return {};
    return helper(0, n);
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.generateTrees(3);
  for (auto node : ret) {
    node->Print();
    std::cout << "===========" << std::endl;
  }
  // std::cout << ret << std::endl;
  return 0;
}
