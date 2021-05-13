#include <bits/stdc++.h>
using namespace std;

/* 坐标版本，每个节点仅仅记录自己的坐标，
但有的时候我们是需要去寻找一些节点的数值的并查集，
则该版本将不适用。 */
namespace index_version {
class disjointSet {

  int totalNodes_; /* 节点总数 */
  int *ancestors;  /* 祖先记录表 */

public:
  disjointSet(int totalNodes) : totalNodes_(totalNodes) {
    ancestors = new int[totalNodes];
    for (int i = 0; i < totalNodes; i++)
      ancestors[i] = i;
  }
  ~disjointSet() { delete[] ancestors; }
  void join(int node1, int node2) {
    int ancestor1 = findAncestor(node1);
    int ancestor2 = findAncestor(node2);
    /* 换祖先 */
    ancestors[ancestor1] = ancestor2;
  }
  int findAncestor(int node) {
    if (node < 0 || node >= totalNodes_)
      return -1;
    /* 如果祖先不是它自己 */
    while (ancestors[node] != node) {
      /* 路径压缩 */
      ancestors[node] = ancestors[ancestors[node]];
      node = ancestors[node];
    }
    return node;
  }
  bool isConnected(int node1, int node2) {
    return findAncestor(node1) == findAncestor(node2);
  }
  void debug() {
    for (size_t i = 0; i < totalNodes_; i++) {
      std::cout << ancestors[i] << " ";
    }
    std::cout << std::endl;
  }
};
} // namespace index_version

namespace nodes_vector_version {

class Node {
  Node *ancestor; /* 祖先 */
public:
  Node() { ancestor = this; }
  Node *findAncestor() {
    Node *cur = this;
    while (cur->ancestor != this) {
      cur->ancestor = cur->ancestor->ancestor;
      cur = cur->ancestor;
    }
    return cur;
  }
  void join(Node *next) {
    Node *ancestor1 = findAncestor();
    Node *ancestor2 = next->findAncestor();
    ancestor1->ancestor = ancestor2;
  }
  bool isConnectTo(Node *next) {
    return next->findAncestor() == findAncestor();
  }
};

class disjointSet {
  vector<Node *> &v_;
  disjointSet(vector<Node *> &v) : v_(v) {}
  Node *findAncestor(int index) { return v_[index]->findAncestor(); }
  void join(Node *lhs, Node *rhs) { lhs->join(rhs); }
  bool isConnected(Node *lhs, Node *rhs) { return lhs->isConnectTo(rhs); }
};
} // namespace nodes_vector_version

namespace kv_version {
class disjointSet {
protected:
  unordered_map<int, int> ancestors; /* 祖先记录表 */

public:
  disjointSet() {}
  ~disjointSet() {}
  void add(int k, int v) { ancestors[k] = v; }
  void join(int node1, int node2) {
    int ancestor1 = findAncestor(node1);
    int ancestor2 = findAncestor(node2);
    /* 换祖先 */
    ancestors[ancestor1] = ancestor2;
  }
  bool findSelf(int node) { return ancestors.find(node) != ancestors.end(); }
  int findAncestor(int node) {
    /* 如果祖先不是它自己 */
    while (ancestors[node] != node) {
      /* 路径压缩 */
      ancestors[node] = ancestors[ancestors[node]];
      node = ancestors[node];
    }
    return node;
  }
  bool isConnected(int node1, int node2) {
    return findAncestor(node1) == findAncestor(node2);
  }
};

class disjointSetWithGroupSize : public disjointSet {
  unordered_map<int, int>
      ancestorCnt; /* 祖先数量记录表 Cnt[i] 是表示有多少个儿子节点 */
  int max_;

public:
  disjointSetWithGroupSize() : disjointSet() { max_ = 1; }
  /* 不支持重复 */
  void add(int k, int v) {
    disjointSet::add(k, v);
    auto c = ancestorCnt.find(v);
    if (c != ancestorCnt.end()) {
      c->second++;
    } else {
      ancestorCnt[v] = 1;
    }
  }
  int findAncestor(int node) {
    /* 如果祖先不是它自己 */
    while (ancestors[node] != node) {
      /* 路径压缩 */
      ancestors[node] = ancestors[ancestors[node]];
      node = ancestors[node];
    }
    return node;
  }
  void join(int node1, int node2) {
    // std::cout << "?" << node1 << " " << node2 << std::endl;
    int ancestor1 = findAncestor(node1);
    int ancestor2 = findAncestor(node2);
    /* 换祖先 */
    if (ancestor1 == ancestor2)
      return;

    if (ancestorCnt[ancestor2] < ancestorCnt[ancestor1]) {
      int tmp = ancestor1;
      ancestor1 = ancestor2;
      ancestor2 = tmp;
    }
    ancestors[ancestor1] = ancestor2;
    ancestorCnt[ancestor2] += ancestorCnt[ancestor1];
    max_ = max(max_, ancestorCnt[ancestor2]);
  }
  int getMaxCnt() { return max_; }
  void debug() {
    for (auto &&i : ancestorCnt) {
      std::cout << i.first << " " << i.second << std::endl;
    }
  }
};

} // namespace kv_version