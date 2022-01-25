#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

void in_order(Node *node, const std::function<void(Node *)> &fn) {
  if (!node)
    return;
  in_order(node->left, fn);
  fn(node);
  in_order(node->right, fn);
}

class Solution {
public:
  Node *treeToDoublyList(Node *root) {
    Node *new_head = nullptr;
    Node *prev = nullptr;
    if (!root)
      return nullptr;
    auto fn = [&](Node *node) {
      if (!new_head) {
        new_head = node;
        prev = new_head;
      } else {
        prev->right = node;
        node->left = prev;
        prev = node;
      }
    };
    in_order(root, fn);
    prev->right = new_head;
    new_head->left = prev;
    return new_head;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
