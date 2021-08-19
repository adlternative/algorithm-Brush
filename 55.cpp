#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <memory>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    bool ret;
    auto size = nums.size();
    auto dp = new bool[size];

    memset(dp, false, size);
    dp[size - 1] = true;

    for (int i = size - 2; i >= 0; i--) {
      for (int j = 1; j != nums[i] + 1; j++) {
        if (i + j <= size - 1 && dp[i + j]) {
          dp[i] = 1;
          break;
        }
      }
    }
    ret = dp[0];
    delete[] dp;
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{2, 0};
  // vector<int> v{2, 3, 1, 1, 4};
  auto ret = s.canJump(v);
  std::cout << ret << std::endl;
  return 0;
}
