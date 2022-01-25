#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> vs;
    bool all_zero = true;
    for (auto &i : nums) {
      if (i)
        all_zero = false;
      vs.push_back(to_string(i));
    }
    if (all_zero) {
      return "0";
    }

    std::function<bool(string_view, string_view)> cmp;
    cmp = [&cmp](string_view l, string_view r) -> bool {
      int l1 = l.size();
      int l2 = r.size();
      for (int i = 0; i < min(l1, l2); i++) {
        int ret = l[i] - r[i];
        if (ret > 0)
          return true;
        else if (ret < 0)
          return false;
      }

      if (l1 > l2) {
        return cmp(l.substr(l2), r);
      } else if (l1 < l2) {
        return cmp(l, r.substr(l1));
      }
      return true;
    };

    sort(vs.begin(), vs.end(), cmp);
    string ret;
    for (const auto &entry : vs)
      ret += entry;
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
