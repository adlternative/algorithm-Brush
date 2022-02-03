#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    vector<ListNode *> nodes;
    auto cur = head;
    while (cur) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    auto lens = nodes.size();

    if (lens <= 2)
      return;

    for (auto i = 0; i < lens / 2; i++) {
      if (nodes[i]->next == nodes[lens - i - 1])
        continue;
      nodes[i]->next = nodes[lens - i - 1];
      nodes[lens - i - 1]->next = nodes[i + 1];
    }
    nodes[lens / 2]->next = nullptr;
  }
};
TEST(Solution, isMatch) {

  Solution s;
  s.reorderList(
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))));
  // EXPECT_EQ(s.(), );
}
