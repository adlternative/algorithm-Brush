#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 如下是包含数字的多个集合：
// * 集合1：{ 1, 2, 3, 4 }
// * 集合2：{ 3, 4, 5 }
// * 集合3：{ 2, 5, 10, 13 }
// * 集合4：{ 10, 20, 30 }
// * 集合5：{ 3, 10 }
// 有的集合，例如集合2和集合5的数据都出现在其他集合中，是冗余数据，这些集合称为冗余集合。
// 设计一个算法，找出冗余集合。
vector<int> findRedundancySet(vector<set<int>> &vs) {
  unordered_map<int, int> i2c;
  vector<int> ret;
  for (auto &s : vs)
    for (auto &i : s)
      i2c[i]++;

  int lens = vs.size();
  for (auto i = 0; i < lens; i++) {
    auto &s = vs[i];
    bool redundancy = true;
    for (auto &i : s) {
      if (i2c[i] == 1)
        redundancy = false;
    }
    if (redundancy)
      ret.push_back(i + 1);
  }
  return ret;
}

int main() {
  vector<set<int>> vs;
  vs.push_back(set<int>{1, 2, 3, 4});
  vs.push_back(set<int>{3, 4, 5});
  vs.push_back(set<int>{2, 5, 10, 13});
  vs.push_back(set<int>{10, 20, 30});
  vs.push_back(set<int>{3, 10});
  auto ret = findRedundancySet(vs);
  for (auto i : ret)
    std::cout << i << std::endl;
}