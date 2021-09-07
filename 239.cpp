#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    /* 先加入 前 k 个 元素 */
    for (int i = 0; i < k; ++i) {
      q.emplace(nums[i], i);
    }
    /* 先将优先队列队顶放到结果中 */
    vector<int> ans = {q.top().first};
    for (int i = k; i < n; ++i) {
      /* 将 一个元素加入 */
      q.emplace(nums[i], i);
      /* i==k 时 只有 0 该弹出
       * i==k+1 时 只有 0，1 该弹出 */
      while (q.top().second <= i - k) {
        q.pop();
      }
      ans.push_back(q.top().first);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  auto ret = s.maxSlidingWindow(nums, 3);
  for (auto i : ret) {
    std::cout << i << std::endl;
  }
  return 0;
}
