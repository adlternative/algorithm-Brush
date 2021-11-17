#include <bits/stdc++.h>

using namespace std;

class MountainArray {
public:
  MountainArray(vector<int> &&v_) : v(std::move(v_)) {}
  int get(int index) { return v[index]; }
  int length() { return v.size(); }
  vector<int> v;
};

class Solution {
public:
  int binarySearchMax(int l, int r, MountainArray &mountainArr) {
    while (l < r) {
      int mid = (l + r) / 2;
      if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }

  int binarySearch(int begin, int end, MountainArray &mountainArr, int target,
                   int reverse) {
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      int midValue = mountainArr.get(mid);
      if ((!reverse && target < midValue) || (reverse && target > midValue)) {
        end = mid;
      } else if ((!reverse && target > midValue) ||
                 (reverse && target < midValue)) {
        begin = mid + 1;
      } else {
        return mid;
      }
    }
    if (mountainArr.get(begin) == target) {
      return begin;
    }
    return -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    auto len = mountainArr.length();
    int begin = 0, end = len - 1;
    int maxIndex = binarySearchMax(begin, end, mountainArr);
    int maxValue = mountainArr.get(maxIndex);
    // int begValue = mountainArr.get(begin);
    // int endValue = mountainArr.get(end);
    int ret = -1;
    if (target == maxValue) {
      return maxIndex;
    } else if (target < maxValue) {
      // std::cout << "[0,mid]" << std::endl;
      ret = binarySearch(0, maxIndex, mountainArr, target, false);
      if (ret == -1) {
        // std::cout << "[mid,max]" << std::endl;
        ret = binarySearch(maxIndex, end, mountainArr, target, true);
      }
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int i;
  MountainArray arr(vector<int>{1, 5, 2});
  while (!cin.eof()) {
    cin >> i;
    auto ret = s.findInMountainArray(i, arr);
    std::cout << ret << std::endl;
  }
  return 0;
}
