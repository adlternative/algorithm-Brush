#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {
    int ret;
    int size = nums.size();
    auto dp = new int[size];
    for (int i = 0; i < size - 1; i++) {
      dp[i] = INT_MAX;
    }
    dp[size - 1] = 0;
    for (int i = size - 2; i >= 0; i--) {
      for (int j = 1; j <= nums[i]; j++) {
        if (i + j <= size - 1 && dp[i + j] != INT_MAX) {
          dp[i] = min(dp[i], dp[i + j] + 1);
        }
      }
    }
    ret = dp[0];
    // for (int i = 0; i < size; i++) {
    //   std::cout << dp[i] << std::endl;
    // }
    delete[] dp;
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  int ss[3] = {3, 3, 3};
  vector<int> v{2, 3, 1, 1, 4};
  auto ret = s.jump(v);
  std::cout << ret << std::endl;
  return 0;
}
