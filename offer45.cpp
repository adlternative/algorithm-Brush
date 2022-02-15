#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  string minNumber(vector<int> &nums) {
    vector<string> v;
    int lens = nums.size();

    for (int i = 0; i < lens; i++)
      v.push_back(to_string(nums[i]));
    sort(v.begin(), v.end(), [](const string &s1, const string &s2) -> bool {
      return s1 + s2 < s2 + s1;
    });
    string ret;
    for (const auto &s : v)
      ret += s;

    return ret;
  }
};
TEST(Solution, isMatch) {
  // Solution s;
  vector<int> v{10, 2};
  // EXPECT_EQ(s.(), );
}
