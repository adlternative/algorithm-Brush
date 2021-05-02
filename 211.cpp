#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
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

class WordDictionary : public Trie {
public:
  // Trie *obj;
  /** Initialize your data structure here. */
  WordDictionary() /*  : obj(new Trie) */ {}
  ~WordDictionary() { /*  delete obj; */
  }
  void addWord(string word) { insert(word); }
  bool dfs(Node *curNode, string word, size_t i) {
    auto &&c = word[i];
    /* 如果是任意字符匹配 */
    if (c == '.') {

      for (auto &&pair : curNode->subNodesMap) {
        /* 搜索终点  */
        if (i == word.size() - 1 && pair.second->endFlag == true)
          return true;
        if (dfs(pair.second, word, i + 1))
          return true;
      }
      return false;
    } else {
      auto iter = curNode->subNodesMap.find(c);
      /* 找不到 */
      if (iter == curNode->subNodesMap.end())
        return false;
      else {
        /* 搜索终点  */
        if (i == word.size() - 1 && iter->second->endFlag == true)
          return true;
        return dfs(iter->second, word, i + 1);
      }
    }
  }
  bool search(string word) {
    auto curNode = root;
    /* 思路dfs */
    size_t len = word.size();
    for (size_t i = 0; i < len; i++) {
      auto &&c = word[i];
      /* 如果是任意字符匹配 那么我们执行dfs对下一个字符进行处理*/
      if (c == '.') {
        for (auto &&pair : curNode->subNodesMap) {
          /* 如果最后一个字符了 */
          if (i == len - 1) {
            /* 如果是结束字符 */
            if (pair.second->endFlag)
              return true;
            else
              /* 否则换个子节点*/
              continue;
            /* 否则继续遍历 */
          } else if (dfs(pair.second, word, i + 1))
            return true;
        }
        return false;
      } else {
        /* 否则看子结点是否是c */
        auto iter = curNode->subNodesMap.find(c);
        /* 找不到 */
        if (iter == curNode->subNodesMap.end())
          return false;
        else {
          /* 找到了则继续 */
          curNode = iter->second;
          /* 如果最后一个字符了 */
          if (i == len - 1) {
            return iter->second->endFlag;
          } else
            continue;
        }
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char const *argv[]) {
  string word("sad");
  WordDictionary *obj = new WordDictionary();
  obj->addWord(word);
  bool param_2 = obj->search(".a.");
  std::cout << param_2 << std::endl;
  delete obj;
  return 0;
}
