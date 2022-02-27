#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  int numberOf2sInRange(int n) {
    int sum = 0;
    string str = to_string(n);
    auto lens = str.size();
    for (int i = 0; i < lens; i++) {
      int high = i == 0 ? 0 : stoi(str.substr(0, i));
      int low = i == lens - 1 ? 0 : stoi(str.substr(i + 1, lens - (i + 1)));

      if (str[i] > '2') {
        /* 12313 */
        sum += (high + 1) * (int)(pow(10, lens - (i + 1)));
      } else if (str[i] < '2') {
        sum += high * (int)(pow(10, lens - (i + 1)));
      } else {
        sum += high * (int)(pow(10, lens - (i + 1))) + low + 1;
      }
    }
    return sum;
  }
};
TEST(Solution, isMatch) {
  std::cout << pow(10,0) << std::endl;
  // Solution s;
  // EXPECT_EQ(s.(), );
}
