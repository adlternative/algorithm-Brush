#include <bits/stdc++.h>
using namespace std;

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