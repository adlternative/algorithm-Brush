#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

// class Solution {
// public:
//   int *parents;

//   /* 你爸爸是我爸爸 */
//   void merge(int i, int j) { parents[find(i)] = parents[j]; }

//   int find(int i) {
//     /* 我爸爸是我自己则返回 否则找我爸爸的爸爸 */
//     if (parents[i] == i)
//       return i;

//     parents[i] = find(parents[i]);
//     return parents[i];
//   }

//   int firstMissingPositive(vector<int> &nums) {
//     int ret;
//     int n = nums.size();
//     parents = new int[n];
//     map<int, int> s; /* nums[index] index */

//     for (int i = 0; i < n; i++) {
//       parents[i] = i;
//     }

//     for (int i = 0; i < n; i++) {
//       if (nums[i] <= 0) {
//         continue;
//       }
//       /* 找 n-1*/
//       auto iter = s.find(nums[i] - 1);
//       if (iter != s.end()) {
//         merge(i, iter->second);
//       }
//       /* 找 n+1*/
//       iter = s.find(nums[i] + 1);
//       if (iter != s.end()) {
//         merge(iter->second, i);
//       }
//       s.insert({nums[i], i});
//     }

//     /* 单纯的找数字1 */
//     // auto iter = s.find(1);
//     // if (iter != s.end()) {
//     //   return 1;
//     // }

//     /* 否则从 map 中 */
//     auto iter = s.begin();
//     if (iter == s.end()) {
//       return -1;
//     } else if (iter->first == 1)
//       return 1;

//     for (int i = 0; i < n; i++) {
//       std::cout << i << nums[i] << parents[i] << std::endl;
//     }

//     return ret;
//   }
// };

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    auto len = nums.size();
    int ret = len + 1;

    for (int i = 0; i < len; i++) {
      if (0 >= nums[i])
        nums[i] = len + 1;
    }
    // for (int i = 0; i < nums.size(); i++) {
    //   std::cout << nums[i] << std::endl;
    // }
    for (int i = 0; i < len; i++) {
      int num = abs(nums[i]) /*  nums[i] */;
      if (num <= len) {
        nums[num - 1] = -abs(nums[num - 1]);
      }
    }

    /* nums 上 一个数字 < 0 意味着它的坐标被标记 意味着该数字出现;而那些
     * 大于零的数字的坐标表示没有出现， */
    for (int i = 0; i < len; i++) {
      if (nums[i] > 0)
        return i + 1;
    }
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {3, 4, -1, 1};
  auto ret = s.firstMissingPositive(nums);
  std::cout << ret << std::endl;

  return 0;
}
