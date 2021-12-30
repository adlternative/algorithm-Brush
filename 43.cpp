#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/*
大数相乘
  123
* 456
------
  738
 615
492
-----

0 = 3(0) * 6(0) = 8  进位是1
1 = 2(1) * 6(0) + 3（0） * 5（1） 组成的 + 1 (进位) = 8 进位是2
2 = 1 * 6 + 2 * 5 + 4 * 3 + 2 （进位） = 0 进位是 3

n = nums1(x) * nums2(n-x) + ... x = 0 ~ n

n [0, len1 + len2 - 2]
*/
class Solution {
public:
  string multiply(string_view num1, string_view num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int lens = len1 + len2;

    if (num1 == "0" || num2 == "0")
      return "0";
    vector<int> dp(lens - 1, 0);
    string ret;
    ret.resize(lens - 1);
    /* dp[0] = nums[0] * nums[1] % 10  */
    int overflow = 0;
    for (int i = 0; i < lens - 1; ++i) {
      dp[i] += overflow;
      overflow = 0;

      for (int j = 0; j <= i && j < len1; j++) {
        int k = i - j;
        if (k >= len2)
          continue;
        int product = (num1[len1 - 1 - j] - '0') * (num2[len2 - 1 - k] - '0');
        dp[i] += product;
      }
      overflow = dp[i] / 10;
      dp[i] %= 10;
    }

    for (int i = 0; i < lens - 1; ++i) {
      ret[i] = dp[lens - 2 - i] + '0';
    }

    if (overflow)
      ret.insert(0, 1, overflow + '0');

    return ret;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.multiply("123", "456"), "56088");
}
