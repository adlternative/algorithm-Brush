#include <bits/stdc++.h> /* 万能头 */
#include <iostream>

using namespace std;

struct TreeNode {
  int color;
  TreeNode *father;
  vector<TreeNode *> sons;
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> color(n);
  vector<int> father(n);
  TreeNode *nodes = new TreeNode[n];

  for (int i = 0; i < n; i++) {
    cin >> nodes[i].color;
  }
  for (int i = 0; i < n; i++) {
    int father_index;
    cin >> father_index;
    if (father_index == 0)
      nodes[i].father = nullptr;
    else {
      nodes[i].father = &nodes[father_index - 1];
      nodes[father_index - 1].sons.push_back(&nodes[i]);
    }
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    /* 黑 */
    if (nodes[i].color) {
      if (!nodes[i].sons.size())
        c1++;
      else {
        int flag = 1;
        for (auto &son : nodes[i].sons) {
          if (son->color) {
            flag = 0;
            break;
          }
        }
        if (flag)
          c1++;
      }
    } else {
      if (!nodes[i].sons.size())
        c2++;
      else {
        int flag = 1;
        for (auto &son : nodes[i].sons) {
          if (son->color) {
            flag = 0;
            break;
          }
        }
        if (!flag)
          c2++;
      }
    }
  }
  std::cout << c2 << " " << c1 << std::endl;
  delete[] nodes;
}
