#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    multiset<int> window;
    int len = nums.size();
    for (size_t i = 0; i < k; i++) {
      window.insert(nums[i]);
    }
    for (size_t i = k; i < len; i++) {
      if (nums[i] > *window.begin()) {
        window.insert(nums[i]);
        window.erase(window.begin());
      }
    }
    return *window.begin();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{3, 2, 1, 5, 6, 4};
  int ret = s.findKthLargest(v, 2);
  std::cout << ret << std::endl;
  return 0;
}
