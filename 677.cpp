#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/* trie-tree */

struct TrieNode {
  TrieNode() : val(0) {
    for (int i = 0; i != 26; i++) {
      nodes[i] = nullptr;
    }
  }

  int val;
  TrieNode *nodes[26];
};

class MapSum {
public:
  MapSum() : root(new TrieNode) {}
  ~MapSum() { delete root; }

  void insert(string key, int val) {
    auto delta = val;

    /* 能找到 */
    auto kv = Cnt.find(key);
    if (kv != Cnt.end()) {
      delta -= kv->second;
    }
    Cnt[key] = val;

    auto node = root;

    for (auto c : key) {
      auto subNodeP = &node->nodes[c - 'a'];
      node = *subNodeP;
      if (!node) {
        *subNodeP = new TrieNode;
        node = *subNodeP;
      }
      node->val += delta;
      continue;
    }
  }

  int sum(string prefix) {
    auto node = root;
    for (auto c : prefix) {
      node = node->nodes[c - 'a'];
      if (!node) {
        return 0;
      }
    }
    return node->val;
  }

  unordered_map<string, int> Cnt;

  TrieNode *root;
};

TEST(MapSum, InsertAndSum) {
  auto mapSum = make_shared<MapSum>();
  mapSum->insert("apple", 3);
  EXPECT_EQ(mapSum->sum("ap"), 3);
  mapSum->insert("app", 2);
  EXPECT_EQ(mapSum->sum("ap"), 5);
  mapSum->insert("apple", 7);
  EXPECT_EQ(mapSum->sum("ap"), 9);
}
