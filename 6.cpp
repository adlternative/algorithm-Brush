#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  string convert(string s, int numRows) {
    int i = 0, j = 0;
    bool down = true;
    queue<char> qs[numRows];

    if (numRows == 1)
      return s;

    for (auto c : s) {
      qs[j].push(c);

      if (j == numRows - 1)
        down = false;
      else if (j == 0)
        down = true;
      if (down) {
        j++;
      } else {
        i++;
        j--;
      }
    }

    string ret;
    for (i = 0; i < numRows; i++) {
      while (qs[i].size()) {
        ret.push_back(qs[i].front());
        qs[i].pop();
      }
    }
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
