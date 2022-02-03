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
  ListNode *detectCycle(ListNode *head) {
    /* 第一步 判断有环 */
    /* 第二步 将环内节点进到 map */
    /* 第三步 遍历 list 找到第一个在 map 中的节点 */
    if (!head)
      return nullptr;
    unordered_set<ListNode *> nodes;
    ListNode *slow = head, *quick = head;
    do {
      slow = slow->next;
      if (quick->next == nullptr)
        return nullptr;
      quick = quick->next;
      if (quick->next == nullptr)
        return nullptr;
      quick = quick->next;
    } while (slow != quick);

    nodes.insert(slow);
    slow = slow->next;
    while (slow != quick) {
      nodes.insert(slow);
      slow = slow->next;
    }

    unordered_set<ListNode *>::iterator find;
    for (find = nodes.find(head); find == nodes.end(); find = nodes.find(head))
      head = head->next;
    return *find;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
