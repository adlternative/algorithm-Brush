#include <bits/stdc++.h> /* 万能头 */

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp {
  bool operator()(ListNode *left, ListNode *right) {
    return left->val > right->val;
  }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int k = lists.size();
    ListNode dummy;
    ListNode *cur = &dummy;
    if (!lists.size())
      return nullptr;
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    for (int i = 0; i < k; i++)
      pq.push(lists[i]);

    while (pq.size()) {
      auto node = pq.top();
      pq.pop();

      cur->next = node;
      cur = node;
      if (node->next)
        pq.push(node->next);
    }

    return dummy.next;
  }
};