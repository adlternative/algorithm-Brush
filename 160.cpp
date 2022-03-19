#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    auto c1 = headA;
    auto c2 = headB;
    while (c1 != c2) {
      if (c1)
        c1 = c1->next;
      else
        c1 = headB;
      if (c2)
        c2 = c2->next;
      else
        c2 = headA;
    }
    return c1;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
