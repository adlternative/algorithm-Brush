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
  int maxArea(vector<int> &height) {
    auto len = height.size();
    size_t l = 0, r = len - 1;

    if (!len)
      return 0;
    int ret = min(height[l], height[r]) * (r - l);
    int sum = 0;
    while (l != r) {
      if (height[l] >= height[r]) {
        r--;
      } else if (height[l] < height[r]) {
        l++;
      }
      sum = min(height[l], height[r]) * (r - l);
      if (sum > ret)
        ret = sum;
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << s.maxArea(v) << std::endl;
  return 0;
}
