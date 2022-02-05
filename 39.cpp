#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  void dfs(vector<int> &candidates, int begin_index, int target) {
    if (!target) {
      ret.push_back(cur);
      return;
    } else if (target < 0) {
      return;
    }

    for (auto i = begin_index; i < candidates.size(); i++) {
      if (target < candidates[i])
        continue;
      cur.emplace_back(candidates[i]);
      dfs(candidates, i, target - candidates[i]);
      cur.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    dfs(candidates, 0, target);
    return std::move(ret);
  }

private:
  vector<vector<int>> ret;
  vector<int> cur;
};
TEST(Solution, isMatch) {
  Solution s;
  // EXPECT_EQ(s.(), );
}
