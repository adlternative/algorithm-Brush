#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Skiplist {
public:
  struct Node {
    /* 直接在一个节点的构造函数中将其层数设置为size层 */
    Node() = default;
    Node(int val, int size = max_level)
        : val(val), level(size)/* , next(new Node[size]) */ {}

    int val;
    // std::shared_ptr<Node[]> next = nullptr; /* next节点的数组 */
    vector<Node *> level;/* next */
  };
  static constexpr int SKIPLIST_P_VAL = RAND_MAX / 2;
  static constexpr const uint32_t max_level = 32;
  int size_ = 1;
  Node head;
  /* 一个节点有 值 和 n层指针 */
  /* 跳表头节点 */
  /* 构造函数就将头节点设置了先 */
  Skiplist() : head(INT_MIN, max_level) {}
  // ~Skiplist() { delte all nodes. }
  // essentially the same as _search
  bool search(int target) {
    /* 获得我们搜索的target在第一层中
      的下一个节点 */
    Node *prev = _search(target)[0];
    /* 返回
      或者找到的这个前一层节点的值恰好等于我们搜索的target */
    return prev->level[0] && prev->level[0]->val == target;
  }
  /* 搜索key,
  返回的是一个所有层恰好小于等于key的节点 */
  vector<Node *> _search(int key) {
    Node *cur = &head;
    vector<Node *> prevs(max_level);
    // through every level, from top to bottom
    // 从当前的最高层向下找，
    for (int i = size_ - 1; i >= 0; i--) {
      // through elements in the current level with smaller value
      /* 如果当前节点的某一个level层(看来是存放这一层下一个节点的指针)
        存在且其值 < 我们想要找的值 */
      while (cur->level[i] && cur->level[i]->val < key)
        /* 跳到这一层链表的下一个节点 */
        cur = cur->level[i];
      /* 退出条件是到了NULL或者找到了这一层链表上的某个节点的
        cur->level[i] >= 我们搜索的key值的节点,并且赋值给prevs */
      /* 也就是满足   cur(prevs)--> key --> cur.level[i] */
      prevs[i] = cur;
    }
    return prevs;
  }
  void add(int num) {
    /* 搜索num，其每一层恰好<=num的节点的vec */
    auto prevs = _search(num);
    /* 获得随机层数 */
    int level = random_level();
    // update size_ and prevs
    /* 如果大于最大层数 */
    if (level > size_) {
      /* 设置“高”层的为head */
      for (int i = size_; i < level; i++)
        prevs[i] = &head;
      /* 更新最高层数 */
      size_ = level;
    }
    /* 申请节点 */
    Node *cur = new Node(num, level);
    // cur  prevs
    for (int i = level - 1; i >= 0; i--) {
      /*  cur->next =prev->next */
      cur->level[i] = prevs[i]->level[i];
      /*  pre->next = cur */
      prevs[i]->level[i] = cur;
    }
    // if there is backward pointer, need to set both cur and cur.next 's back
    // pointer Note that the back poinet of the first valid node is nullptr
    // instead of head
  }
  bool erase(int num) {
    /* 搜出<=num的前驱节点集合 */
    auto prevs = _search(num);
    /* 找不到num节点，那就返回 */
    if (!prevs[0]->level[0] || prevs[0]->level[0]->val != num)
      return false;
    /* 否则获得该节点 */
    Node *del = prevs[0]->level[0];
    // from prev->cur->next to prev->next
    for (int i = 0; i < size_; i++)
      /* 然后prev->next= cur->next */
      if (prevs[i]->level[i] == del)
        prevs[i]->level[i] = del->level[i];
    delete del;
    // update size_.
    while (size_ > 1 && !head.level[size_ - 1])
      size_--;
    // if there is backward poinet, need to set cur.next.back to cur.back
    return true;
  }
  static int random_level() {
    int level = 1;
    while (rand() < SKIPLIST_P_VAL && level < max_level)
      level++;
    return level;
  }
};
int main(int argc, char const *argv[]) {
  Skiplist s;

  return 0;
}
