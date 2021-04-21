#include <bits/stdc++.h>
#include <cstdlib>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
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
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  int cnt;
  ListNode *head_;
  Solution(ListNode *head) : head_(head) {}
  /** Returns a random node's value. */
  int getRandom() {
    cnt = 1;
    int ret = head_->val;
    ListNode *cur = head_->next;
    while (cur) {
      cnt++;
      if ((rand() % cnt + 1) == cnt) {
        ret = cur->val;
      }
      cur = cur->next;
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  ListNode *ln[5];
  srand(time(NULL));
  for (int i = 4; i != -1; i--) {
    if (i != 4)
      ln[i] = new ListNode(i, ln[i + 1]);
    else
      ln[i] = new ListNode(i);
  }
  Solution s(ln[0]);
  map<int, int> m;
  for (size_t i = 0; i < 1000; i++) {
    int j = s.getRandom();
    auto iter = m.find(j);
    if (iter == m.end()) {
      m[j] = 0;
    }
    iter->second++;
  }
  for (auto &&i : m) {
    std::cout << i.first << ":" << i.second << std::endl;
  }

  return 0;
}
