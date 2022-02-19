#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
  long long GetCount(vector<long long> &nums, int n, int d) {
    int r, l;
    long long ret = 0;
    int lr = 2;
    for (l = 0; l < n - 2; l++) {
      // for (r = l + 2; r < n && nums[r] - nums[l] <= d; r++) {
      //   ret += r - l - 1;
      //   ret = ret % 99997867;
      // }
      /* l + 2 -> n 二分找第一个大于 nums[l] + d 的 r*/
      int ll = max(lr, l + 2);
      lr = n - 1;
      while (ll <= lr) {
        int mid = ((lr - ll) >> 1) + ll;
        if (nums[mid] > nums[l] + d) {
          lr--;
        } else {
          ll++;
        }
      }
      if (lr == l + 1)
        continue;

      ret += ((lr - l) * (lr - l - 1) / 2) % 99997867;
      ret = ret % 99997867;
    }
    return ret;
  }
};

int main() {
  int n, d;
  cin >> n >> d;
  Solution s;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long j;
    cin >> j;
    v.push_back(j);
  }
  cout << s.GetCount(v, n, d) << endl;
}