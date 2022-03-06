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
  void reverselist(ListNode *dummy, ListNode *tail) {
    auto pre = dummy->next;
    auto cur = dummy->next->next;

    while (cur != tail) {
      auto tmp = cur->next;
      pre->next = tmp;
      cur->next = dummy->next;
      dummy->next = cur;
      cur = tmp;
    }
  }

  bool isPalindrome(ListNode *head) {
    if (!head->next)
      return true;

    ListNode dummy(0, head);
    ListNode *quick = &dummy;
    ListNode *slow = &dummy;

    bool dou = false; /* 偶数 */
    while (true) {
      quick = quick->next;
      if (!quick) {
        dou = true;
        break;
      }
      quick = quick->next;
      if (!quick)
        break;
      slow = slow->next;
    }

    auto mtail = slow->next;
    reverselist(&dummy, mtail);

    ListNode *cur = dummy.next;
    ListNode *cur2 = dou ? mtail : mtail->next;

    while (cur != mtail && cur2) {
      if (cur->val != cur2->val)
        return false;
      cur = cur->next;
      cur2 = cur2->next;
    }
    return cur == mtail && !cur2;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  ListNode *nodes = new ListNode[3];
  nodes[0].val = 1;
  nodes[0].next = &nodes[1];
  nodes[1].val = 0;
  nodes[1].next = &nodes[2];
  nodes[2].val = 1;
  // nodes[2].next = &nodes[3];
  // nodes[3].val = 1;

  EXPECT_EQ(s.isPalindrome(&nodes[0]), true);
  delete[] nodes;
}
