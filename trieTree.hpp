#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

class TrieNode {
public:
  TrieNode() : isWord(false) {}
  TrieNode(char value) : isWord(false), value_(value) {}
  void insert(string s, bool reverse_ = false) {
    auto cur = this;
    if (reverse_)
      reverse(s.begin(), s.end());
    if (!s.size())
      return;
    for (auto &&i : s) {
      auto next = cur->subNodes.find(i);
      if (next == cur->subNodes.end()) {
        auto node = new TrieNode(i);
        cur->subNodes.insert({i, node});
        cur = node;
      } else {
        cur = next->second;
      }
    }
    cur->isWord = true;
  }

  struct RawTrieNode {
    explicit RawTrieNode(TrieNode *node, size_t raw) : node_(node), raw_(raw) {}
    TrieNode *node_;
    size_t raw_;
  };
  static void print_RawTrieNode(RawTrieNode *top) {
    std::cout << top->node_->value_ << " " << top->raw_ << " "
              << top->node_->isWord << "    ";
  }
  /* 层次遍历 */
  void traverse(void (*handler)(RawTrieNode *)) {
    queue<RawTrieNode> q;
    size_t raw = 0;
    size_t prev_raw = 0;
    for (auto &&i : subNodes) {
      q.push(RawTrieNode(i.second, raw));
    }
    while (!q.empty()) {

      auto top = q.front();
      q.pop();
      if (prev_raw != top.raw_)
        std::cout << std::endl;
      handler(&top);
      prev_raw = top.raw_;
      raw = top.raw_ + 1;
      for (auto &&i : top.node_->subNodes) {
        q.push(RawTrieNode(i.second, raw));
      }
    }
  }
  bool search_(string s, size_t index) {
    if (s.size() == index) {
      return isWord;
    }
    auto iter = subNodes.find(s[index]);
    if (iter != subNodes.end()) {
      return iter->second->search_(s, index + 1);
    } else {
      return false;
    }
  }
  bool search(string s) { return search_(s, 0); }

  char value_;
  bool isWord;
  map<char, TrieNode *> subNodes;
};