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
  int combinationSum4(vector<int> &nums, int target) {
    long long len = nums.size();
    long long dp[target + 1];
    dp[0] = 1;
    for (long i = 1; i <= target; i++) {
      dp[i] = 0;
      for (long j = 0; j < len; j++) {
        if (i >= nums[j] && dp[i - nums[j]] < INT_MAX - dp[i])
          dp[i] += dp[i - nums[j]];
      }
    }
    return dp[target];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // vector<int> v{1, 2, 3};
  vector<int> v{1, 2, 3};
  int ret = s.combinationSum4(v, 4);
  std::cout << ret << std::endl;
  return 0;
}
