#include <bits/stdc++.h>
#include <fmt/format.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
  friend ostream &operator<<(ostream &os, Node *node);
};

ostream &operator<<(ostream &os, Node *node) {
  os << fmt::format("val:{} ", node->val);
  if (node->random != NULL)
    os << fmt::format("random:{} ", node->random->val);
  return os;
}

class Solution {
public:
  Node *copyRandomList(Node *head) {
    // Node dummy(0);
    // dummy.next = head;
    // auto prev = &dummy;
    if (!head)
      return head;
    auto cur = head;
    Node *new_head = nullptr;

    while (cur) {
      auto next = cur->next;
      auto copy_node = new Node(cur->val);
      if (!new_head) [[unlikely]]
        new_head = copy_node;
      copy_node->next = next;
      cur->next = copy_node;
      cur = next;
    }

    // Node dummy(0);
    // dummy.next = head;
    // auto prev = &dummy;
    auto prev = head;
    cur = prev->next;

    while (prev) {
      auto next = cur->next;
      if (prev->random)
        cur->random = prev->random->next;
      prev = next;
      if (prev)
        cur = prev->next;
    }

    prev = head;
    cur = prev->next;

    while (prev) {
      auto next = cur->next;
      if (next)
        cur->next = next->next;
      prev->next = next;
      prev = next;
      if (prev)
        cur = prev->next;
    }

    return new_head;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  auto n1 = new Node(7);
  auto n2 = new Node(13);
  auto n3 = new Node(11);
  auto n4 = new Node(10);
  auto n5 = new Node(1);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n2->random = n1;
  n3->random = n5;
  n4->random = n3;
  n5->random = n1;

  auto ret = s.copyRandomList(n1);
  auto cur = ret;
  while (cur) {
    std::cout << cur << std::endl;
    cur = cur->next;
  }
}
