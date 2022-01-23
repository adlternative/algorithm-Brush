#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool oneEditAway(string_view first, string_view second) {
    int lenf = first.length();
    int lens = second.length();
    if (std::abs(lenf - lens) > 1)
      return false;
    int curf = 0, curs = 0;
    int diff = -1;

    while (curf < lenf && curs < lens) {
      if (first[curf] != second[curs]) {
        if (lenf == lens) {
          if (diff == -1) {
            diff = curf;
            curf++;
            curs++;
          } else {
            return false;
          }
        } else {
          if (diff == -1) {
            diff = curf;
            if (lenf > lens)
              curf++;
            else
              curs++;
          } else {
            return false;
          }
        }
      } else {
        curf++;
        curs++;
      }
    }

    return true;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.oneEditAway("pale", "ple"), true);
  EXPECT_EQ(s.oneEditAway("pales", "pal"), false);
}
