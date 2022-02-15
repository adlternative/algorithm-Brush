#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int calculateBit(int val) {
    int ret = 0;
    while (val) {
      val /= 10;
      ret++;
    }
    return ret;
  }
  int compress(vector<char> &chars) {
    int len = chars.size();
    if (len <= 1)
      return len;

    int ret = 0;
    char last_ch = chars[0];
    int count = 1;
    vector<char> arr(1, last_ch);

    for (int i = 1; i < len; ++i) {
      if (chars[i] == last_ch)
        count++;
      else {
        ret += 1;
        auto str = to_string(count);
        if (count != 1) {
          ret += str.size();
          for (auto &c : str)
            arr.push_back(c);
        }
        /* 将 count 重置 */
        count = 1;
        arr.push_back(chars[i]);
      }
      last_ch = chars[i];
    }

    ret += 1;
    auto str = to_string(count);
    if (count != 1) {
      ret += str.size();
      for (auto &c : str)
        arr.push_back(c);
    }
    chars = std::move(arr);
    return ret;
  }
};

TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
