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
  Solution(vector<int> &nums) : nums_(nums), len(nums.size()) {
    srand(time(NULL));
  }
  int cnt;
  size_t len;
  vector<int> nums_;

  int pick(int target) {
    int ret = 0;
    cnt = 0;
    for (size_t i = 0; i < len; i++) {
      if (nums_[i] == target) {
        cnt++;
        if (rand() % cnt + 1 == cnt) {
          ret = i;
        }
      }
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v{1, 2, 3, 3, 3};
  Solution s(v);
  map<int, int> m;
  for (size_t i = 0; i < 1000; i++) {
    int j = s.pick(3);
    auto iter = m.find(j);
    if (iter == m.end()) {
      m[j] = 0;
    }
    iter->second++;
  }
  for (auto &&i : m) {
    std::cout << i.first << ":" << i.second << std::endl;
  }

  return 0;
}
