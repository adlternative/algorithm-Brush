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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode presudoNode(0, head);
    auto prev = &presudoNode;
    auto cur = head;
    auto next = head->next;

    for (; cur && next;) {
      auto tmp = next->next;
      cur->next = tmp;
      prev->next = next;
      next->next = cur;
      prev = cur;
      cur = tmp;
      if (tmp)
        next = tmp->next;
    }
    return presudoNode.next;
  }
};
TEST(Solution, isMatch) { Solution s; }
