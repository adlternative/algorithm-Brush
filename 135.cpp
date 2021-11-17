#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int candy(vector<int> &ratings) {
    auto len = ratings.size();
    int sum = 1;
    int pre = 1; /* 前一个人分的糖数量 */
    /* 递增长度，递减长度 */
    int inc = 1, dec = 0;
    for (int i = 1; i < len; i++) {
      if (ratings[i] > ratings[i - 1]) {
        /* 升 */
        dec = 0;
        pre = pre + 1;
        sum += pre;
        inc = pre;
      } else if (ratings[i] < ratings[i - 1]) {
        /* 降 */
        dec++;
        /* 升降的区间相同 */
        if (dec == inc) {
          dec++;
        }
        sum += dec;
        pre = 1; /* 这个人拿到一个1个糖果 */
      } else {
        /* 相等 */
        dec = 0;
        pre = 1; /* 这个人拿到一个1个糖果 */
        sum += pre;
        inc = pre;
      }
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> ratings{1, 0, 2};
  auto ret = s.candy(ratings);
  std::cout << ret << std::endl;
  return 0;
}
