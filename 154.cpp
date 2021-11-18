#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    auto len = nums.size();
    int l = 0, r = len - 1;
    /* 二分搜索最小值（旋转后为极小值） */
    while (l < r) {
      int mid = (r - l) / 2 + l;
      int mid_val = nums[mid];
      /* 极小值 */
      if (mid_val > nums[r]) {
        l = mid + 1;
      } else if (mid_val < nums[r]) {
        r = mid;
      } else {
        r--;
      }
    }
    return nums[r];
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{5, 6, 1, 2, 3, 4};
  auto ret = s.findMin(v);
  std::cout << ret << std::endl;
  return 0;
}
