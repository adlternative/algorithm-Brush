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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<ListNode *> stk1, stk2;
    auto cur = l1;
    while (cur) {
      stk1.push(cur);
      cur = cur->next;
    }
    cur = l2;
    while (cur) {
      stk2.push(cur);
      cur = cur->next;
    }
    int ob = 0;
    ListNode *cur_node = nullptr;
    while (!stk1.empty() && !stk2.empty()) {
      int sum = stk1.top()->val + stk2.top()->val + ob;
      if (sum >= 10) {
        sum %= 10;
        ob = 1;
      } else {
        ob = 0;
      }
      auto new_node = new ListNode(sum, cur_node);
      cur_node = new_node;
      stk1.pop();
      stk2.pop();
    }
    if (!stk1.empty()) {
      while (!stk1.empty()) {
        int sum = stk1.top()->val + ob;
        if (sum >= 10) {
          sum %= 10;
          ob = 1;
        } else {
          ob = 0;
        }
        auto new_node = new ListNode(sum, cur_node);
        cur_node = new_node;
        stk1.pop();
      }
    } else {
      while (!stk2.empty()) {
        int sum = stk2.top()->val + ob;
        if (sum >= 10) {
          sum %= 10;
          ob = 1;
        } else {
          ob = 0;
        }
        auto new_node = new ListNode(sum, cur_node);
        cur_node = new_node;
        stk2.pop();
      }
    }
    if (ob == 1) {
        auto new_node = new ListNode(1, cur_node);
        cur_node = new_node;
    }

    return cur_node;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
