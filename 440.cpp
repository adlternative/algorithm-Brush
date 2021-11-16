#include <bits/stdc++.h>

using namespace std;

#if defined Plan1

class Solution {
public:
  struct DictCmp {
    bool operator()(int left, int right) {
      return to_string(left) > to_string(right);
    }
  };

  int findKthNumber(int n, int k) {
    priority_queue<int, vector<int>, DictCmp> queue;
    for (int i = 1; i <= n; i++) {
      queue.push(i);
    }
    while (--k) {
      queue.pop();
    }
    return queue.top();
  }
};
#endif

class Solution {
public:
  /* n为最大数，获得前缀为 prefix 的节点的树上所有节点数量 */
  long getCount(long prefix, long n) { /*  1, 10 */
    auto cur = prefix;
    auto next = prefix + 1;
    int count = 0;
    while (cur <= n) { /* 15 */
      count += min(n + 1, next) - cur;
      cur *= 10;
      next *= 10;
    }
    return count;
  }
  /* 从 [1,n] 寻找字典序第k大的数字 */
  long findKthNumber(int n, int k) { /* 10,3 */
    /* prefix 是前缀值 "1"， p是第几个 */
    long prefix = 1, p = 1;
    /* 计算子节点数量 */
    for (; p < k;) {
      long subNodeCount = getCount(prefix, n);
      /* p=1,sub=2 == 3  prefix = 2 p = 3 */
      if (p + subNodeCount <= k) {
        /* 说明 prefix 还太小，跳到下一个数字 */
        prefix++;
        p += subNodeCount;
      } else {
        /* 说明 prefix 对上了，要在子树找 */
        prefix *= 10;
        p++;
      }
    }
    return prefix;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.findKthNumber(10, 3);
  std::cout << ret << std::endl;
  return 0;
}
