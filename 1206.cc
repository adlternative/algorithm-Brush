#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Node {
public:
  Node(int key, int height) : key_(key), next_(new Node *[height]) {
    // std::cout << "Node:" << key << " " << height << std::endl;
  }
  ~Node() {
    if (next_)
      delete[] next_;
  }
  Node *Next(int level) { return next_[level]; }
  // Node &operator=(const Node &node) {
  //   if (&node != this) {
  //     key_ = node.key_;
  //     next_ = node.next_;
  //   }
  //   return *this;
  // }
  void SetNext(int level, Node *next) { next_[level] = next; }
  int Key() { return key_; }

private:
  int key_;
  Node **next_;
};

class Skiplist {
public:
  Skiplist() : head_(new Node(0, MaxHeight)), cur_max_height_(1) {
    srand(time(NULL));
    for (int i = 0; i < MaxHeight; i++)
      head_->SetNext(i, nullptr);
  }
  ~Skiplist() {
    auto node = head_->Next(0);
    while (node) {
      auto temp = node->Next(0);
      delete node;
      node = temp;
    }
    delete head_;
  }

  bool search(int target) {
    /* 首先从 head 开始 */
    Node *x = head_;
    /* 从当前的最高层开始 */
    int cur_level = cur_max_height_ - 1;

    while (true) {
      Node *next = x->Next(cur_level);
      /* 如果下个节点是 null 或者下个节点比当前要找的数字大 */
      if (next == nullptr || target < next->Key()) {
        /* 如是最底层那无了 */
        if (cur_level == 0)
          return false;
        /* 否则看 x 的下一层 （向下移动）*/
        cur_level--;
      } else if (target == next->Key()) {
        return true;
      } else {
        /* 向右移动 */
        x = next;
      }
    }
  }

  void add(int num) {
    Node *prev[MaxHeight];
    /* 首先从 head 开始 */
    Node *x = head_;
    /* 从当前的最高层开始 */
    int cur_level = cur_max_height_ - 1;

    while (true) {
      Node *next = x->Next(cur_level);
      /* 如果下个节点是 null 或者下个节点比当前要找的数字大 */
      if (next == nullptr || num < next->Key()) {
        /* 设置新节点的当前层前一个节点 */
        prev[cur_level] = x;
        /* 如是最底层那无了 */
        if (cur_level == 0)
          break;
        /* 否则看 x 的下一层 （向下移动）*/
        cur_level--;
      } else {
        /* 向右移动 */
        x = next;
      }
    }

    /* 一个随机高度 */
    int new_height = rand() % (MaxHeight);
    if (!new_height)
      new_height = 1;
    /* 新节点 */
    auto new_node = new Node(num, new_height);
    /* 设置 [cur_max_height, new_height] 指针 */
    for (int i = cur_max_height_; i < new_height; i++)
      prev[i] = head_;
    /* 更新最高高度 */
    if (new_height > cur_max_height_)
      cur_max_height_ = new_height;
    /* 设置链表指针 */
    for (int i = 0; i < new_height; i++) {
      new_node->SetNext(i, prev[i]->Next(i));
      prev[i]->SetNext(i, new_node);
    }
  }

  void debug() {
    for (int i = 0; i < cur_max_height_; i++) {
      std::cout << "level " << i << " ";
      int count = 0;
      auto node = head_->Next(i);
      while (node) {
        std::cout << node->Key() << " ";
        node = node->Next(i);
        count++;
      }
      std::cout << " count:" << count << std::endl;
    }
  }

  bool erase(int num) {
    Node *prev[MaxHeight];
    /* 首先从 head 开始 */
    Node *x = head_;
    /* 从当前的最高层开始 */
    int cur_level = cur_max_height_ - 1;
    Node *find = nullptr;
    int find_level = -1;
    while (true) {
      Node *next = x->Next(cur_level);
      /* 如果下个节点是 null 或者下个节点比当前要找的数字大  或者相等 */
      if (next == nullptr || num < next->Key() ||
          (num == next->Key() && (!find || find == next))) {
        if (next && num == next->Key()) {
          if (!find) {
            /* 如果这是第一个找到的 */
            find = next;
            find_level = cur_level;
          }
          /*  else if (find == next) {}
           */
          prev[cur_level] = x;
        }
        /* 如是最底层那无了 */
        if (cur_level == 0)
          break;
        /* 否则看 x 的下一层 （向下移动）*/
        cur_level--;
      } else {
        /* 向右移动 */
        x = next;
      }
    }

    // /* 更新最高高度 */
    // if (new_height > cur_max_height_)
    //   cur_max_height_ = new_height;
    // /* 设置链表指针 */
    if (find) {
      for (int i = find_level; i >= 0; i--) {
        prev[i]->SetNext(i, find->Next(i));
        if (!head_->Next(i))
          cur_max_height_--;
      }
      delete find;
    }
    return find_level != -1;
  }

private:
  int cur_max_height_;
  static constexpr int MaxHeight = 10;
  Node *head_; /* 头指针数组 */
};

TEST(Solution, isMatch) {
  Skiplist *skiplist = new Skiplist();
  skiplist->add(1);
  // skiplist->debug();
  skiplist->add(2);
  // skiplist->debug();
  skiplist->add(3);
  // skiplist->debug();
  EXPECT_EQ(skiplist->search(0), false);
  skiplist->add(4);
  // skiplist->debug();
  EXPECT_EQ(skiplist->search(1), true);
  EXPECT_EQ(skiplist->search(2), true);
  EXPECT_EQ(skiplist->search(3), true);
  EXPECT_EQ(skiplist->search(4), true);
  // skiplist->debug();
  EXPECT_EQ(skiplist->erase(0), false);
  EXPECT_EQ(skiplist->erase(1), true);
  EXPECT_EQ(skiplist->search(1), false);
  delete skiplist;
}

TEST(Solution, isMatch2) {
  Skiplist *skiplist = new Skiplist();
  skiplist->add(0);
  skiplist->add(5);
  skiplist->add(2);
  skiplist->add(1);
  EXPECT_EQ(skiplist->search(0), true);
  EXPECT_EQ(skiplist->erase(5), true);
  EXPECT_EQ(skiplist->search(2), true);
  EXPECT_EQ(skiplist->search(3), false);
  EXPECT_EQ(skiplist->search(2), true);
  delete skiplist;
}

TEST(Solution, isMatch3) {

  vector<string> opts{
      "Skiplist", "add",    "add",    "add",    "add",    "add",    "add",
      "add",      "add",    "add",    "erase",  "search", "add",    "erase",
      "erase",    "erase",  "add",    "search", "search", "search", "erase",
      "search",   "add",    "add",    "add",    "erase",  "search", "add",
      "search",   "erase",  "search", "search", "erase",  "erase",  "add",
      "erase",    "search", "erase",  "erase",  "search", "add",    "add",
      "erase",    "erase",  "erase",  "add",    "erase",  "add",    "erase",
      "erase",    "add",    "add",    "add",    "search", "search", "add",
      "erase",    "search", "add",    "add",    "search", "add",    "search",
      "erase",    "erase",  "search", "search", "erase",  "search", "add",
      "erase",    "search", "erase",  "search", "erase",  "erase",  "search",
      "search",   "add",    "add",    "add",    "add",    "search", "search",
      "search",   "search", "search", "search", "search", "search", "search"};
  vector<int> values{
      0,  16, 5, 14, 13, 0,  3,  12, 9, 12, 3,  6,  7,  0,  1,  10, 5,  12, 7,
      16, 7,  0, 9,  16, 3,  2,  17, 2, 17, 0,  9,  14, 1,  6,  1,  16, 9,  10,
      9,  2,  3, 16, 15, 12, 7,  4,  3, 2,  1,  14, 13, 12, 3,  6,  17, 2,  3,
      14, 11, 0, 13, 2,  1,  10, 17, 0, 5,  8,  9,  8,  11, 10, 11, 10, 9,  8,
      15, 14, 1, 6,  17, 16, 13, 4,  5, 4,  17, 16, 7,  14, 1};

  Skiplist *skiplist = nullptr;
  for (int i = 0; i < values.size(); i++) {
    if (opts[i] == "Skiplist") {
      skiplist = new Skiplist();
    } else if (opts[i] == "add") {
      skiplist->add(values[i]);
    } else if (opts[i] == "search") {
      skiplist->search(values[i]);
    } else if (opts[i] == "erase") {
      // std::cout << values[i] << std::endl;
      skiplist->erase(values[i]);
    } else {
      /* empty */
    }
  }
  delete skiplist;
}