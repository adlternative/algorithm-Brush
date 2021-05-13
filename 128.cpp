#include "disjointSet.hpp"
#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace kv_version;
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int len = nums.size();
    if (!len)
      return 0;
    set<int> set_;
    disjointSetWithGroupSize djs;
    for (size_t i = 0; i < len; i++) {
      if (set_.find(nums[i]) == set_.end()) {
        djs.add(nums[i], nums[i]);
        set_.insert(nums[i]);
      }
      if (djs.findSelf(nums[i] + 1)) {
        djs.join(nums[i], nums[i] + 1);
      }
      if (djs.findSelf(nums[i] - 1)) {
        djs.join(nums[i], nums[i] - 1);
      }
    }
    // djs.debug();
    return djs.getMaxCnt();
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{1, 2, 0, 1};
  // vector<int> v{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  auto ret = s.longestConsecutive(v);
  std::cout << ret << std::endl;
  return 0;
}
