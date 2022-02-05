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
  ListNode *mergeHelp(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode *cur = &dummy;
    while (l1 && l2) {
      int v1 = l1->val;
      int v2 = l2->val;
      if (v1 < v2) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    if (l1) {
      cur->next = l1;
    } else {
      cur->next = l2;
    }

    return dummy.next;
  }

  ListNode *sortHelp(ListNode *head, ListNode *tail) {
    if (!head || !head->next)
      return head;

    auto slow = head, quick = head;
    while (1) {
      if (quick->next == tail)
        break;
      quick = quick->next;
      if (quick->next == tail)
        break;
      quick = quick->next;
      /* 此时 slow 在 mid  */
      slow = slow->next;
    }
    auto next = slow->next;
    slow->next = nullptr;
    return mergeHelp(sortHelp(head, nullptr), sortHelp(next, tail));
  }
  ListNode *sortList(ListNode *head) { return sortHelp(head, nullptr); }
};

TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
