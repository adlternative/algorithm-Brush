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
    int endIndex = -1;
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
  void insert(string word, int index) {
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
    curNode->endIndex = index;
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
  int search(string &word, int beg, int end, bool reverse_ = false) {
    auto curNode = root;
    if (!reverse_)
      for (int i = beg; i < end; i++) {
        auto &&c = word[i];
        auto iter = curNode->subNodesMap.find(c);
        if (iter == curNode->subNodesMap.end())
          return -1;
        else {
          curNode = iter->second;
          continue;
        }
      }
    else {
      for (int i = end - 1; i >= beg; i--) {
        auto &&c = word[i];
        auto iter = curNode->subNodesMap.find(c);
        if (iter == curNode->subNodesMap.end())
          return -1;
        else {
          curNode = iter->second;
          continue;
        }
      }
    }
    return curNode->endIndex;
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
/*
  m.len>o.len
  acbb|ca 别人是前缀反过来
  bbcd|dc 别人是后缀反过来

  m.len<o.len
  ca|acbb 自己是别人前缀反过来
  dc|bbcd 自己是后缀反过来

  m.len==o.len
  abcd|dcba 恰好相反

  现在我们需要从前缀树中寻找自己是否是别人的前后缀?
 */
class Solution {
public:
  static bool isABBA(string &s, int beg, int end) {
    for (int i = beg; i <= (end + beg) / 2; i++) {
      if (s[i] != s[end + beg - i]) {
        return false;
      }
    }
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ret;
    Trie tree;
    auto len = words.size();
    for (int i = 0; i < len; i++) {
      tree.insert(words[i], i);
    }
    for (int i = 0; i < len; i++) {
      /* 对于每一个字符串,我们在字典树中查找其位置 */
      int wordlen = words[i].size();
      for (int j = 0; j <= wordlen; j++) {
        /* 首先搜索前缀有没有回文 [0~j-1]*/
        if (j && isABBA(words[i], 0, j - 1)) {
          /* 去树上找是否存在 words[j,wordlen] 的字符串 end-1 ->beg*/
          auto index = tree.search(words[i], j, wordlen, true);
          if (index != -1 && i != index)
            ret.emplace_back(vector<int>{index, i});
        }
        /* 搜索后缀有没有回文 */
        if (j != wordlen && isABBA(words[i], j, wordlen - 1)) {
          /* 去树上找是否存在 words[j+1,wordlen]的字符串 */
          auto index = tree.search(words[i], 0, j, true);
          if (index != -1 && i != index)
            ret.emplace_back(vector<int>{i, index});
        }
      }
    }
    return ret;
  }
};

void test() {
  vector<string> vs{"abcd", "dcba", "lls", "s", "sssll"};
  // vector<string> vs{"a", "abc", "aba", ""};
  Solution s;
  auto &&ret = s.palindromePairs(vs);
  for (auto &&i : ret) {
    for (auto &&j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}
void test2() {
  string s("ab");
  assert(Solution::isABBA(s, 0, s.size() - 1) == 0);
  s = "aba";
  assert(Solution::isABBA(s, 0, s.size() - 1) == 1);
  s = "abcba";
  assert(Solution::isABBA(s, 0, s.size() - 1) == 1);
  s = "abccba";
  assert(Solution::isABBA(s, 0, s.size() - 1) == 1);
  s = "a";
  assert(Solution::isABBA(s, 0, s.size() - 1) == 1);
  // s = "aca";
  // s += "";
  s = "";
  s += "aca";
  assert(Solution::isABBA(s, 0, s.size() - 1) == 1);
}

int main(int argc, char const *argv[]) {
  test();
  return 0;
}
