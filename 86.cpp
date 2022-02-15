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
  ListNode *partition(ListNode *head, int x) {
    /* 尾插 */
    ListNode dummy(0, head);
    auto cur = head;
    auto tail = &dummy;
    auto prev = &dummy;
    while (cur) {
      if (cur->val < x) {
        prev->next = cur->next;
        cur->next = tail->next;
        tail->next = cur;
        tail = cur;
        if (prev->next == cur)
          prev = cur;
        cur = prev->next;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
