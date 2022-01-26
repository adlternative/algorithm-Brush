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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || !k)
      return head;
    ListNode fake_head(0, head);

    auto tail = head;
    int count = 1;
    while (tail->next) {
      tail = tail->next;
      count++;
    }
    k %= count;
    if (!k)
      return head;

    auto prev = &fake_head;
    int left = count - k;
    auto cur = head;
    while (left--) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = nullptr; /* nullptr */
    tail->next = fake_head.next;
    return cur;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
