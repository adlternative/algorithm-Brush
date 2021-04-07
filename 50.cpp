#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  /* pow(x,n) 求3^5=(3^2)^2*3=3^4^1*3 */
  /* 2^10= 4^5*1= 16^2*4     */
  double myPow(double x, int n) {
    double sum = x;
    double extra = 1;
    bool rev = 0;
    long ln = n;
    if (x == 1)
      return sum;
    if (n < 0) {
      rev = 1;
      ln = -(double)n;
    }
    if (ln == 0)
      return 1;
    while (ln >= 1) { // n不是0
      if (ln == 1)
        break;
      if (ln & 1)       // 5&1==1
        extra *= sum;  //额外的参数中乘一个x
      ln >>= 1;         // 5/2=2 2/2=1
      sum = sum * sum; // 9
    }
    if (rev == 1)
      return 1 / (sum * extra);
    else
      return sum * extra;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.myPow(2.00000, -2147483648) << std::endl;
  return 0;
}
