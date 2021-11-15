#include <bits/stdc++.h>
#include <ctype.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  struct Val {
    Val() : i(0), type(INT_T) {}
    enum { INT_T, CHAR_T } type;
    union {
      int i;
      char c;
    };
  };

  vector<Val> midfix_to_subfix(string s) {
    vector<Val> results;
    size_t len = s.size();
    stack<char> stk;

    for (int i = 0; i < len; i++) {
      char ch = s[i];
      switch (ch) {
      case '+':
      case '-': {
        if (!i || s[i - 1] == '(') {
          Val v;
          results.push_back(v);
        } else {
          while (stk.size()) {
            auto top = stk.top();
            if (top != '-') { /* 更高优先级 */
              break;
            }
            stk.pop();
            Val v;
            v.type = Val::CHAR_T;
            v.c = top;
            results.push_back(v);
          }
        }
        stk.push(ch);
        break;
      }
      // case '*':
      // case '/':
      case '(':
        stk.push(ch);
        break;
      case ')': {
        // char cur = 0;
        while (stk.size()) {
          ch = stk.top();
          stk.pop();
          if (ch == '(')
            break;
          Val v;
          v.type = Val::CHAR_T;
          v.c = ch;
          results.push_back(v);
        }
        if (ch == '(') {
          break;
        } else {
          return results;
        }
      }
      case ' ':
        continue;
      default:
        break;
      }
      if (!isdigit(s[i]))
        continue;
      Val v;
      int old_i = i;
      while (i < len && isdigit(s[i])) {
        int val = s[i] - '0';
        v.i = 10 * v.i + val;
        i++;
        continue;
      }
      if (old_i != i) {
        results.push_back(v);
        i--;
      }
      continue;
    }
    while (stk.size()) {
      Val v;
      v.type = Val::CHAR_T;
      v.c = stk.top();
      results.push_back(v);
      stk.pop();
    }
    return results;
  }

  int calculate(string s) {
    int ret;
    stack<Val> stk;
    auto vec = midfix_to_subfix(s);

    for (auto entry : vec) {
      switch (entry.type) {
      case Val::INT_T:
        stk.push(entry);
        break;
      case Val::CHAR_T: {
        Val v;
        if (stk.size() >= 2) {
          auto first = stk.top();
          stk.pop();
          auto second = stk.top();
          stk.pop();
          switch (entry.c) {
          case '+':
            v.i = first.i + second.i;
            stk.push(v);
            break;
          case '-':
            v.i = second.i - first.i;
            stk.push(v);
            break;
          default:
            break;
          }
        } else if (stk.size() == 1) {
          auto first = stk.top();
          stk.pop();

          switch (entry.c) {
          case '+':
            v.i = first.i;
            stk.push(v);
            break;
          case '-':
            v.i = -first.i;
            stk.push(v);
            break;
          default:
            break;
          }
        }
        break;
      }
      }
    }
    ret = stk.top().i;
    return ret;
  }
};

TEST(Solution, calculate) {
  Solution s;
  auto vec = s.midfix_to_subfix("1 - (-2)");
  /* 256 123 2 + 3 * +  */
  for (int i = 0; i < vec.size(); i++) {
    switch (vec[i].type) {
    case Solution::Val::CHAR_T:
      std::cout << vec[i].c << " ";
      break;
    case Solution::Val::INT_T:
      std::cout << vec[i].i << " ";
      break;
    }
  }
  // std::cout << std::endl;
  // EXPECT_EQ(ss, "212+3*+");
  /* 1 4 5 2 + + 3 - + 6 8 + +  */
  auto ret = s.calculate("(6)-(8)-(7)+(1+(6))");
  EXPECT_EQ(ret, -2);
  ret = s.calculate("(1+(4+5+2)-3)+(6+8)");
  EXPECT_EQ(ret, 23);

  ret = s.calculate("1+1");
  EXPECT_EQ(ret, 2);
  ret = s.calculate("2-1 + 2");
  EXPECT_EQ(ret, 3);
  ret = s.calculate("-1 + 2");
  EXPECT_EQ(ret, 1);
  ret = s.calculate("1 - (-2)");
  EXPECT_EQ(ret, 3);
}