#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = 0;
    for (auto &i : nums)
      sum += i;

    if (sum % k)
      return false;

    int avg = sum / k;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    if (nums.back() > avg)
      return false;
    /* k 个桶 */
    vector<int> arr(k, avg);
    return dfs(nums, arr, len - 1, k);
  }

  bool dfs(vector<int> &nums, vector<int> &arr, int pos, int k) {
    if (pos < 0) [[unlikely]] {
      return true;
    }

    for (int i = 0; i < k; i++) {
      if (arr[i] < nums[pos])
        continue;

      arr[i] -= nums[pos];
      if (dfs(nums, arr, pos - 1, k)) [[unlikely]]
        return true;
      arr[i] += nums[pos];
    }
    return false;
  }
};
TEST(Solution, isMatch) {
  Solution s;
  vector<int> f{4, 3, 2, 3, 5, 2, 1};
  EXPECT_EQ(s.canPartitionKSubsets(f, 4), true);
}
