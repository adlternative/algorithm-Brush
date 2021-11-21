#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int calcF(int eggCnt, int chanceCnt, vector<vector<int>> &mem) {
    if (eggCnt == 1 || chanceCnt == 1)
      return chanceCnt + 1;
    /* 蛋碎（向下可以确定的楼数） + 蛋不碎（向上可以确定的楼数） */
    if (mem[eggCnt - 1][chanceCnt - 1] == -1)
      mem[eggCnt - 1][chanceCnt - 1] = calcF(eggCnt - 1, chanceCnt - 1, mem);
    if (mem[eggCnt][chanceCnt - 1] == -1)
      mem[eggCnt][chanceCnt - 1] = calcF(eggCnt, chanceCnt - 1, mem);
    return mem[eggCnt - 1][chanceCnt - 1] + mem[eggCnt][chanceCnt - 1];
  }

  int superEggDrop(int k, int n) {
    vector<vector<int>> mem(k + 1, vector<int>(n + 1, -1));

    int T = 1;
    while (calcF(k, T, mem) < n + 1) {
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
