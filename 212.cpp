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

class Solution {
public:
  int **map_;
  Trie *tree = nullptr;
  set<string> set_;
  vector<string> ret;
  int row;
  int col;
  using Node = Trie::Node;
  struct direction {
    int p; /* 水平 */
    int q; /* 垂直 */
  } direct[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool canAccess(int i, int j, direction &d) {
    if ((i + d.p >= row || i + d.p < 0) || (j + d.q >= col || j + d.q < 0))
      return false;
    if (map_[i + d.p][j + d.q])
      return false;
    return true;
  }
  void dfs(vector<vector<char>> &board, int i, int j, Node *node) {
    map_[i][j] = true;
    if (!node)
      return;
    /* 标记已经访问 */
    /* 如果到达终点，我们就将单词放进去 */
    if (node->endFlag && set_.find(node->endString) == set_.end()) {
      ret.push_back(node->endString);
      set_.insert(node->endString);
    }

    for (int k = 0; k < 4; k++) {
      /* 如果可以走 */
      if (canAccess(i, j, direct[k])) {
        /* 在子节点中寻找线索 */
        int nexti = i + direct[k].p;
        int nextj = j + direct[k].q;
        char c = board[nexti][nextj];

        auto &&iter = node->subNodesMap.find(c);
        if (iter == node->subNodesMap.end()) {
          continue;
        } else {
          /* 继续遍历 */
          dfs(board, nexti, nextj, iter->second);
          /* 还原现场 */
          map_[nexti][nextj] = false;
          continue;
        }
      }
    }
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    /* 初始化 */
    row = board.size();
    if (row == 0)
      return ret;
    col = board[0].size();
    tree = new Trie;
    map_ = new int *[row];
    for (int i = 0; i < row; i++) {
      map_[i] = new int[col];
      memset(map_[i], 0, col * sizeof(int));
    }
    /* 插入单词到字典树 */
    for (auto &&i : words) {
      tree->insert(i);
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        auto c = board[i][j];
        /* 找第一个字符 */
        auto iter = tree->root->subNodesMap.find(c);
        /* 找不到滚 */
        if (iter == tree->root->subNodesMap.end())
          continue;
        /* 否则以c为起点 Dfs */
        dfs(board, i, j, iter->second);
        /* 清空记录表 */
        for (int i = 0; i < row; i++) {
          memset(map_[i], 0, col * sizeof(int));
        }
      }
    }
    for (int i = 0; i < row; i++) {
      delete[] map_[i];
    }
    delete[] map_;

    delete tree;
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> board;
  board.emplace_back(vector<char>{'a', 'b', 'c'});
  board.emplace_back(vector<char>{'a', 'e', 'd'});
  board.emplace_back(vector<char>{'a', 'f', 'g'});
  vector<string> words{"abcdefg", "gfedcbaaa", "eaabcdgfa",
                       "befa",    "dgc",       "ade"};
  auto ret = s.findWords(board, words);
  for (auto &&i : ret) {
    std::cout << i << std::endl;
  }
  return 0;
}
