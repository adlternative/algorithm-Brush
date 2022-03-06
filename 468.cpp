#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool checkIPV4Segment(const string_view &seg) {
    int lens = seg.length();
    if (!lens)
      return false;
    int value = 0;
    for (int i = 0; i < lens; i++) {
      auto &c = seg[i];
      if (!isdigit(c))
        return false;
      if (i == 0 && c == '0' && lens > 1)
        return false;
      value = 10 * value + c - '0';
    }
    return value <= 255 && value >= 0;
  }

  bool checkIPV4(const string_view &IP) {
    int dot_count = 0;
    int lens = IP.size();
    int beg = 0;
    for (int i = 0; i < lens; i++) {
      if (IP[i] == '.') {
        dot_count++;
        if (dot_count >= 4)
          return false;
        if (!checkIPV4Segment(IP.substr(beg, i - beg)))
          return false;
        beg = i + 1;
      }
    }

    if (!checkIPV4Segment(IP.substr(beg, lens - beg)))
      return false;

    return dot_count == 3;
  }

  bool checkIPV6Segment(const string_view &seg) {
    int lens = seg.length();
    if (lens > 4 || !lens)
      return false;

    for (int i = 0; i < lens; i++) {
      if (!((seg[i] >= '0' && seg[i] <= '9') ||
            (seg[i] >= 'a' && seg[i] <= 'f') ||
            (seg[i] >= 'A' && seg[i] <= 'F')))
        return false;
    }
    return true;
  }

  bool checkIPV6(const string_view &IP) {
    int colon_count = 0;
    int lens = IP.size();
    int beg = 0;
    for (int i = 0; i < lens; i++) {
      if (IP[i] == ':') {
        colon_count++;
        if (colon_count >= 8)
          return false;

        if (!checkIPV6Segment(IP.substr(beg, i - beg)))
          return false;
        beg = i + 1;
      }
    }

    if (!checkIPV6Segment(IP.substr(beg, lens - beg)))
      return false;

    return colon_count == 7;
  }

  string validIPAddress(string_view queryIP) {
    if (queryIP.length() > 39)
      return "Neither";
    if (queryIP.find('.') == string_view::npos)
      return checkIPV6(queryIP) ? "IPv6" : "Neither";
    else
      return checkIPV4(queryIP) ? "IPv4" : "Neither";
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.validIPAddress("172.16.254.1"), "IPv4");
}
TEST(Solution, isMatch2) {
  Solution s;
  EXPECT_EQ(s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"), "IPv6");
}
