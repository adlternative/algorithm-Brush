#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
/*
1~9
10~99
100~999
1000~9999
出现1的个数... 1~9 (1)
10~99 :10 ~19

算出当前数字多少位12345 5位
个位出1 周期是10 那么可以转 12345/10 轮 贡献1
十位出1 周期是100 那么可以转 12345/100 轮 贡献10
百位出1 周期是1000 那么可以转 12345/1000 轮 贡献100 *(12+1)
千位出1 周期是10000 那么可以转 12345/10000 =1 轮  （>1的情况）贡献1000 *(1+1)
万位出1 周期是100000 那么转了 0轮 + （=1的情况）（2345+1）
注意小于1的情况就不用多记
54132 贡献=100 54 *(100+0) +54132%100
13 /10 =1 (1+1)*1=2
13/100 =0 3+1=4
和是6
 */
class Solution {
public:
  int countDigitOne(int n) {
    long long sum = 0;
    long long cur = n; // 100
    long long pek;
    long long cont = 1; //贡献
    while (cur) {
      pek = cur % 10; // 0
      cur /= 10;      // 10
      // std::cout << "!" << cur << " " << pek << " " << cont << std::endl;
      sum += (cur + (pek > 1 ? 1 : 0)) * cont; // 10
      // std::cout << "sum" << sum << std::endl;
      if (pek == 1) {
        // std::cout << "？" << sum << " "
        //           << " " << n << " " << cont << std::endl;
        sum += n % cont + 1;
      }
      cont *= 10; // 10
    }
    return sum;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  // 1 11 21 ... 91 ->10次
  // 10 11 12 ...19 10次
  // 100 1
  std::cout << s.countDigitOne(1410065408) << std::endl;
  return 0;
}
