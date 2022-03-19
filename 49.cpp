#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ret;
    unordered_map<string, int> str2idx;
    for (auto &str : strs) {
      auto temp = str;
      sort(temp.begin(), temp.end());
      auto iter = str2idx.find(temp);
      if (iter == str2idx.end()) {
        str2idx.emplace(temp, ret.size());
        ret.emplace_back(vector<string>{str});
      } else {
        ret[iter->second].push_back(str);
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
