
#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    int pos = 1;
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    while (cur && pos < left) {
      pre = pre->next;
      cur = cur->next;
      pos++;
    }
    ListNode *tailNode = cur;
    while (cur && pos <= right) {
      ListNode *next = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      cur = next;
      tailNode->next = next;
      pos++;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  return 0;
}
