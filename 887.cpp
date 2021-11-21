#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int calcF(int eggCnt, int chanceCnt) {
    if (eggCnt == 1 || chanceCnt == 1)
      return chanceCnt + 1;
    /* 蛋碎（向下可以确定的楼数） + 蛋不碎（向上可以确定的楼数） */
    return calcF(eggCnt - 1, chanceCnt - 1) + calcF(eggCnt, chanceCnt - 1);
  }

  int superEggDrop(int k, int n) {
    int T = 1;
    while (calcF(k, T) < n + 1) {
      T++;
    }
    return T;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.superEggDrop(3, 14);
  std::cout << ret << std::endl;
  return 0;
}
