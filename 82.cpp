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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode presudoNode(0, head);
    auto cur = head, prev = &presudoNode;

    unordered_map<int, int> vals;
    while (cur) {
      vals[cur->val]++;
      cur = cur->next;
    }
    cur = head;
    while (cur) {
      auto iter = vals.find(cur->val);
      if (iter != vals.end() && iter->second >= 2) {
        /* delete cur */
        auto tmp = cur->next;
        prev->next = tmp;
        cur = tmp;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    return presudoNode.next;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
