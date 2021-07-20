#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
class Solution {
public:
  int minPairSum(vector<int> &nums) {
    int len = nums.size();
		sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[len - 1];
    for (int i = 1, j = len - 2; i < len && j >= 0; i++, j--) {
      ret = max(ret, nums[i] + nums[j]);
    }
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums{3, 5, 2, 3};
  auto ret = s.minPairSum(nums);
  cout << "ret = " << ret << endl;
  return 0;
}
