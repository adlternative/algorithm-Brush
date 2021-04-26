#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

/*
考虑匹配第n个字符的失配数量最小值 dp[n]
先默认dp[n]=dp[n-1]+1,当作没有配平
向前看 是否会出现匹配单词，如果出现则更新该点的失配
单词的数量最小值。
*/

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
  // bool search_(string s, size_t index) {
  //   if (s.size() == index) {
  //     return isWord;
  //   }
  //   auto iter = subNodes.find(s[index]);
  //   if (iter != subNodes.end()) {
  //     return iter->second->search_(s, index + 1);
  //   } else {
  //     return false;
  //   }
  // }
  // bool search_(const char *p, int *dis, bool reverse) {
  //   auto iter = subNodes.find(*p);
  //   if (iter != subNodes.end()) {
  //     (*dis)++;
  //     if (isWord)
  //       return true;
  //     if (reverse)
  //       return iter->second->search_(p - 1, dis, reverse);
  //     else
  //       return iter->second->search_(p + 1, dis, reverse);
  //   } else
  //     return false;
  // }
  // bool search(string s) { return search_(s, 0); }
  // bool search(string s, int end, int *dis, bool reverse) {
  //   *dis = 0;
  //   return search_(s.c_str() + end, dis, reverse);
  // }

  char value_;
  bool isWord;
  map<char, TrieNode *> subNodes;
};

class Solution {
public:
  int respace(vector<string> &dictionary, string sentence) {
    TrieNode root;
    int ret = 0;
    int len = sentence.size();
    int dp[len + 1];

    for (auto &&i : dictionary) {
      root.insert(i, true);
    }
    // root.traverse(TrieNode::print_RawTrieNode);
    memset(dp, 0, sizeof(dp));
    for (size_t i = 1; i <= len; i++) { // i==len
      dp[i] = dp[i - 1] + 1;
      auto cur = &root;
      for (size_t j = i; j >= 1; j--) { // j=len
        /* 对应不上则退出 */
        if (cur->subNodes.find(sentence[j - 1]) == cur->subNodes.end())
          break;
        /* 如果找到了单词 */
        else {
          cur = cur->subNodes[sentence[j - 1]];
          if (cur->isWord) //如果是单词末尾
            dp[i] = min(dp[i], dp[j - 1]);
        }
      }
    }

    return dp[len];
  }
};

int main(int argc, char const *argv[]) {
  // TrieNode root;
  // root.insert("abcdef");
  // root.insert("abc");
  // root.insert("bn");
  // root.insert("bc");
  // root.traverse(TrieNode::print_RawTrieNode);
  // bool ret = root.search("abc");
  // std::cout << ret << std::endl;
  // ret = root.search("abcdef");
  // std::cout << ret << std::endl;
  // char s[] = "asklfjhlakjfedcba";
  // ret = root.search_(s + strlen(s) - 1, true);
  // std::cout << ret << std::endl;

  // vector<string> vs{"looked", "just", "like", "her", "brother"};
  vector<string> vs{"potimzz"};
  string sentence("potimzzpotimzz");
  Solution s;
  int ret = s.respace(vs, sentence);
  std::cout << ret << std::endl;
  return 0;
}
