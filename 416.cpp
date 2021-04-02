#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
/*
 *背包问题
 * 求dp[i][sum/2]
 *
 *
 *
 */

using namespace std;
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto &&i : nums)
      sum += i;
    if (sum % 2)
      return false;
    sum /= 2;
    int len = nums.size();
    /*
     *二维数组的解法
     */
    // vector<vector<bool>> dp(len + 1, vector<bool>(sum + 1, false));
    // for (size_t i = 0; i <= len; i++) {
    //   dp[i][0] = true;
    // }

    // for (int i = 1; i <= len; i++) {   //第i个值
    //   for (int j = 1; j <= sum; j++) { //总和到sum/2
    //     if (j >=
    //         nums[i - 1]) //空间足以装下新的,但可以装也可以不装(就是背包的max)
    //       dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
    //     else /* 但是装不下了那么就直接不装这个 */
    //       dp[i][j] = dp[i - 1][j];
    //   }
    // }

    // return dp[len][sum];
    /*
     *一维数组的解法
     */
    vector<bool> dp(sum + 1,
                    false); // dp[j]=true/false 表示sum是j的时候能不能装下
    dp[0] = true;           //
    for (int i = 1; i <= len; i++) {
      for (int j = sum; j >= 1; j--) {
        if (j >= nums[i - 1])
          dp[j] = dp[j - nums[i - 1]] | dp[j];
      }
    }
    return dp[sum];
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums{1, 5, 11, 5};
  auto ret = s.canPartition(nums);
  if (ret)
    printf("1");
  else
    printf("0");
  return 0;
}
