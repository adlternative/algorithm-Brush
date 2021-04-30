#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[]) {
  auto word = "abc";
  Trie *obj = new Trie();
  obj->insert(word);
  bool param_2 = obj->search(word);
  bool param_3 = obj->startsWith("a");
  std::cout << param_2 << param_3 << std::endl;

  delete obj;

  return 0;
}
