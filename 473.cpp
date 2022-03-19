#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/* dfs */
class Solution {
public:
  bool dfs(vector<pair<int, int>> &matchsticksCnt, vector<int> &slot, int index,
           vector<bool> &visited) {
    // if (index == matchsticks.size()) {
    // }

    int value = matchsticksCnt[index].first;

    // /* not choice */
    // if (dfs(matchsticksCnt, slot, index + 1, visited))
    //   return true;

    for (int i = 0; i < matchsticksCnt[index].second; i++) {
      // int sum = matchsticksCnt[index].first * i;
       
      for (int j = 0; j < 4; j++) {

      }
      /* choice */
      visited[index] = true;
      if (dfs(matchsticksCnt, slot, index + 1, visited))
        return true;
      visited[index] = false;
    }

    return false;
  }

  bool makesquare(vector<int> &matchsticks) {
    int sum = 0;
    sort(matchsticks.begin(), matchsticks.end(), greater<>());
    vector<pair<int, int>> matchsticksCnt;
    int lens = matchsticks.size();
    for (int i = 0; i < lens; i++) {
      sum += matchsticks[i];
      if (!i || matchsticks[i] != matchsticks[i - 1]) {
        matchsticksCnt.emplace_back(matchsticks[i], 1);
      } else {
        ++matchsticksCnt[matchsticksCnt.size() - 1].second;
      }
    }
    if (sum & 3)
      return false;

    vector<bool> visited(matchsticksCnt.size());
    vector<int> slot(4, sum / 4);
    return dfs(matchsticksCnt, slot, 0, visited);
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 1, 2, 2, 2};
  EXPECT_EQ(s.makesquare(v), true);
}
