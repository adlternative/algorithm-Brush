#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
  vector<vector<int>> edges;
  vector<int> indegrees;
  vector<bool> used;

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    indegrees.resize(numCourses);
    used.resize(numCourses, false);

    for (auto &v : prerequisites) {
      edges[v[0]].push_back(v[1]);
      indegrees[v[1]]++;
    }

    while (true) {
      bool change = false;
      for (int i = 0; i < numCourses; i++) {
        /* 寻找那些入度为 0 的先下手 */
        if (!used[i] && !indegrees[i]) {
          /* 找到了其所有对应出端点 */
          auto &v = edges[i];
          for (int j : v) {
            /* 将这些点的入度-- */
            indegrees[j]--;
          }
          used[i] = true;
          if (!change)
            change = true;
        }
      }

      if (!change) {
        /* 说明没找到 没被使用 且 入度为 0 的点 */
        bool finish = true;
        for (auto use : used) {
          finish &= use;
        }
        return finish;
      }
    }
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<vector<int>> prerequisites = {{1, 0}};
  EXPECT_EQ(s.canFinish(2, prerequisites), true);
}
