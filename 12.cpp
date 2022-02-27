#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {

public:
  string table(char ch, int bit) {
    string ret;
    switch (ch) {
    case '0':
      break;
    case '1': {
      if (bit == 0)
        ret += 'I';
      else if (bit == 1)
        ret += 'X';
      else if (bit == 2)
        ret += 'C';
      else if (bit == 3)
        ret += 'M';
      break;
    }
    case '2': {
      if (bit == 0)
        ret += "II";
      else if (bit == 1)
        ret += "XX";
      else if (bit == 2)
        ret += "CC";
      else if (bit == 3)
        ret += "MM";
      break;
    }
    case '3': {
      if (bit == 0)
        ret += "III";
      else if (bit == 1)
        ret += "XXX";
      else if (bit == 2)
        ret += "CCC";
      else if (bit == 3)
        ret += "MMM";
      break;
    }
    case '4': {
      if (bit == 0)
        ret += "IV";
      else if (bit == 1)
        ret += "XL";
      else if (bit == 2)
        ret += "CD";
      break;
    }
    case '5': {
      if (bit == 0)
        ret += "V";
      else if (bit == 1)
        ret += "L";
      else if (bit == 2)
        ret += "D";
      break;
    }
    case '6': {
      if (bit == 0)
        ret += "VI";
      else if (bit == 1)
        ret += "LX";
      else if (bit == 2)
        ret += "DC";
      break;
    }
    case '7': {
      if (bit == 0)
        ret += "VII";
      else if (bit == 1)
        ret += "LXX";
      else if (bit == 2)
        ret += "DCC";
      break;
    }
    case '8': {
      if (bit == 0)
        ret += "VIII";
      else if (bit == 1)
        ret += "LXXX";
      else if (bit == 2)
        ret += "DCCC";
      break;
    }
    case '9': {
      if (bit == 0)
        ret += "IX";
      else if (bit == 1)
        ret += "XC";
      else if (bit == 2)
        ret += "CM";
      break;
    }
    }
    return ret;
  }

  string intToRoman(int num) {
    string ret;
    auto str = to_string(num);
    int lens = str.length();

    for (int i = 0; i < lens; i++)
      ret += table(str[i], lens - 1 - i);
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
