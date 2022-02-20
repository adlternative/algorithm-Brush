#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  vector<vector<int>> ret;
  vector<int> v;

  void dfs(vector<int> &nums, int pos, vector<bool> &visit) {
    int lens = nums.size();
    if (pos == lens) {
      ret.push_back(v);
      return;
    }
    for (int i = 0; i < lens; i++) {
      if (visit[i] || (i && nums[i] == nums[i - 1] && !visit[i - 1]))
        continue;
      v.push_back(nums[i]);
      visit[i] = true;
      dfs(nums, pos + 1, visit);
      visit[i] = false;
      v.pop_back();
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> visit(nums.size());
    dfs(nums, 0, visit);
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
