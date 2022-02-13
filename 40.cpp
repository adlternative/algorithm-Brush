#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  vector<vector<int>> ret;
  map<int, int> v2c;
  vector<int> tmp;
  int target_;

  void dfs(map<int, int>::iterator iter, int sum) {
    if (sum > target_)
      return;
    else if (sum == target_) {
      ret.push_back(tmp);
      return;
    }

    if (iter == v2c.end())
      return;

    int value = iter->first;
    int count = iter->second;
    ++iter;

    /* 0 个 value */
    dfs(iter, sum);

    for (int i = 1; i <= count; i++) {
      tmp.push_back(value);
      dfs(iter, sum + i * value);
    }

    for (int i = 0; i < count; i++)
      tmp.pop_back();
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    target_ = target;
    int lens = candidates.size();
    if (target <= 0 || !lens)
      return ret;

    for (int i = 0; i < lens; i++)
      v2c[candidates[i]]++;

    dfs(v2c.begin(), 0);

    return ret;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> candidates;
}
