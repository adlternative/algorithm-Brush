#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;
namespace origin {

class Trie {
public:
  struct Node {
    bool endFlag = false;
    map<char, Node *> subNodesMap; /* 字符 到 节点 的映射*/
    void clear() {
      if (subNodesMap.empty())
        return;
      for (auto &&i : subNodesMap) {
        i.second->clear();
        delete i.second;
      }
    }
  };
  Node *root;
  /** Initialize your data structure here. */
  Trie() : root(new Node) {}
  ~Trie() {
    root->clear();
    delete root;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    auto curNode = root;
    for (auto &&c : word) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter != curNode->subNodesMap.end()) {
        curNode = iter->second;
        continue;
      } else {
        auto node = new Node;
        curNode->subNodesMap.insert({c, node});
        curNode = node;
        continue;
      }
    }
    curNode->endFlag = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto curNode = root;
    for (auto &&c : word) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter == curNode->subNodesMap.end())
        return false;
      else {
        curNode = iter->second;
        continue;
      }
    }
    return curNode->endFlag;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto curNode = root;
    for (auto &&c : prefix) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter == curNode->subNodesMap.end())
        return false;
      else {
        curNode = iter->second;
        continue;
      }
    }
    return true;
  }
};

} // namespace origin
namespace end_with_string {

class Trie {
public:
  struct Node {
    bool endFlag = false;
    string endString;
    map<char, Node *> subNodesMap; /* 字符 到 节点 的映射*/
    void clear() {
      if (subNodesMap.empty())
        return;
      for (auto &&i : subNodesMap) {
        i.second->clear();
        delete i.second;
      }
    }
  };
  Node *root;
  /** Initialize your data structure here. */
  Trie() : root(new Node) {}
  ~Trie() {
    root->clear();
    delete root;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    auto curNode = root;
    for (auto &&c : word) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter != curNode->subNodesMap.end()) {
        curNode = iter->second;
        continue;
      } else {
        auto node = new Node;
        curNode->subNodesMap.insert({c, node});
        curNode = node;
        continue;
      }
    }
    curNode->endFlag = true;
    curNode->endString = std::move(word);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto curNode = root;
    for (auto &&c : word) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter == curNode->subNodesMap.end())
        return false;
      else {
        curNode = iter->second;
        continue;
      }
    }
    return curNode->endFlag;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto curNode = root;
    for (auto &&c : prefix) {
      auto iter = curNode->subNodesMap.find(c);
      if (iter == curNode->subNodesMap.end())
        return false;
      else {
        curNode = iter->second;
        continue;
      }
    }
    return true;
  }
};

} // namespace end_with_string

namespace can_print_version {
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

} // namespace can_print_version