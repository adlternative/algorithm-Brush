#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  // stack<int> stk;
  // bool dfs(string_view s, int index) {
  //   int lens = s.length();

  //   if (lens == index) {
  //     if (stk.empty())
  //       return true;
  //     else
  //       return false;
  //   }

  //   switch (s[index]) {
  //   case '(': {
  //     stk.push(s[index]);
  //     if (dfs(s, index + 1))
  //       return true;
  //     stk.pop();
  //     break;
  //   }
  //   case ')': {
  //     if (stk.empty())
  //       return false;
  //     char c = stk.top();
  //     stk.pop();
  //     if (dfs(s, index + 1))
  //       return true;
  //     stk.push(c);
  //     break;
  //   }
  //   case '*':
  //     /* case 1 ( */
  //     stk.push(s[index]);
  //     if (dfs(s, index + 1))
  //       return true;
  //     stk.pop();

  //     /* case 2 ) */
  //     if (stk.empty())
  //       return false;
  //     char c = stk.top();
  //     stk.pop();
  //     if (dfs(s, index + 1))
  //       return true;
  //     stk.push(c);

  //     /* case 3 * */
  //     if (dfs(s, index + 1))
  //       return true;
  //     break;
  //   }
  //   return false;
  // }

  bool checkValidString(string_view s) {
    /* return dfs(s, 0);  */
    int min_count = 0, max_count = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
      switch (s[i]) {
      case '(':
        min_count++;
        max_count++;
        break;
      case ')':
        min_count = max(min_count - 1, 0);
        max_count--;
        if (max_count < 0)
          return false;
        break;
      case '*':
        min_count = max(min_count - 1, 0);
        max_count++;
        if (max_count < 0)
          return false;
        break;
      }
    }
    return min_count == 0;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.checkValidString("(*))"), true);
  EXPECT_EQ(s.checkValidString("(*)"), true);
  EXPECT_EQ(s.checkValidString("()"), true);
  EXPECT_EQ(s.checkValidString("("), false);
  EXPECT_EQ(s.checkValidString("())"), false);
}
