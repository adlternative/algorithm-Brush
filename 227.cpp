#include <bits/stdc++.h>
#include <gtest/gtest.h>

/* -->   + - * / */
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
  enum Priority { ADD_SUB, MUL_DIV };

  Solution() {
    PriorityMap['+'] = ADD_SUB;
    PriorityMap['-'] = ADD_SUB;
    PriorityMap['*'] = MUL_DIV;
    PriorityMap['/'] = MUL_DIV;
  }

  vector<Val> midfix_to_subfix(string s) {
    vector<Val> results;
    size_t len = s.size();
    stack<char> stk;

    for (int i = 0; i < len; i++) {
      char ch = s[i];
      switch (ch) {
      case '+':
      case '-':
      case '*':
      case '/': {
        if ((ch == '+' || ch == '-') && !i) {
          /* 0 */
          Val v;
          results.push_back(v);
        } else {
          while (stk.size()) {
            auto top = stk.top();
            if (PriorityMap[ch] > PriorityMap[top]) { /* 弹出栈顶更高优先级 */
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
    /* 剩下所有栈中元素弹栈 */
    while (stk.size()) {
      Val v;
      v.type = Val::CHAR_T;
      v.c = stk.top();
      results.push_back(v);
      stk.pop();
    }
    return results;
  }

  int calculateOp(int first, char op, int second) {
    int ret;
    switch (op) {
    case '+':
      ret = first + second;
      break;
    case '-':
      ret = first - second;
      break;
    case '*':
      ret = first * second;
      break;
    case '/':
      ret = first / second;
      break;
    }
    return ret;
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
          v.i = calculateOp(second.i, entry.c, first.i);
          stk.push(v);
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
  map<char, Priority> PriorityMap;
};

TEST(Solution, calculate) {
  Solution s;
  auto ret = s.calculate("1+1*3-4");
  EXPECT_EQ(ret, 0);
  ret = s.calculate("3/2");
  EXPECT_EQ(ret, 1);
  ret = s.calculate(" 3+5 / 2 ");
  EXPECT_EQ(ret, 5);
  ret = s.calculate("3+2*2");
  EXPECT_EQ(ret, 7);
  ret = s.calculate("1-2+3");
  EXPECT_EQ(ret, 2);
  ret = s.calculate("2-1-3");
  EXPECT_EQ(ret, -2);
  ret = s.calculate("2*3-2");
  EXPECT_EQ(ret, 4);
  ret = s.calculate("2/3*4");
  EXPECT_EQ(ret, 0);
  ret = s.calculate("2+3*4");
  EXPECT_EQ(ret, 14);

  /* 2*3-2 */
  /* 2/3*4 */

  /* 2+ 3*4 */
}
