#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/* 36 进制加法 0-9 a-z

  z3
+ a1
----

*/

int getValue(char ch) {
  return ch >= '0' && ch <= '9' ? ch - '0' : ch - 'a' + 10;
}
char getChar(int v) { return v <= 9 ? v + '0' : v - 10 + 'a'; }
void add2(char c1, char c2, int &b, char &r) {
  int sum = getValue(c1) + getValue(c2) + b;
  if (sum >= 36) {
    b = 1;
    r = getChar(sum % 36);
  } else {
    b = 0;
    r = getChar(sum);
  }
}

string add36Strings(string_view num1, string_view num2) {
  int len1 = num1.length();
  int len2 = num2.length();
  string ret;
  int ob = 0;
  char r;

  for (int i = 0; i < min(len1, len2); i++) {
    add2(num1[len1 - 1 - i], num2[len2 - 1 - i], ob, r);
    ret.push_back(r);
  }
  if (len1 > len2) {
    for (int i = len2; i < len1; i++) {
      add2('0', num1[len1 - 1 - i], ob, r);
      ret.push_back(r);
    }
  } else if (len1 < len2) {
    for (int i = len1; i < len2; i++) {
      add2('0', num2[len2 - 1 - i], ob, r);
      ret.push_back(r);
    }
  }
  if (ob == 1)
    ret.push_back('1');

  std::reverse(ret.begin(), ret.end());
  return ret;
}

TEST(Solution, isMatch) { EXPECT_EQ(add36Strings("1b", "2x"), "48"); }
