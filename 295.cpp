#include <bits/stdc++.h>

using namespace std;
class MedianFinder {
public:
  MedianFinder() : left(nums.end()), right(nums.end()) {}

  void addNum(int num) {
    nums.insert(num);
    int len = nums.size();
    if (len == 1) {
      right = left = nums.begin();
      return;
    }
    if (len & 1) {
      /* 偶 -> 奇 */
      if (num < *left) {
        left--;
        while (left != right) {
          left++;
          right--;
        }
      } else if (num >= *right) {
        right++;
        while (left != right) {
          left++;
          right--;
        }
      } else {
        left++;
        right = left;
      }
    } else {
      /* 奇 -> 偶 */
      /* 如果值小于中位数 */
      if (num < *left) {
        left--;
      } else {
        right++;
      }
    }
  }

  double findMedian() { return (double)(*left + *right) / 2.0; }

  multiset<int> nums;
  /* 双指针 */
  multiset<int>::iterator left, right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(int argc, char const *argv[]) {
  MedianFinder *obj = new MedianFinder();
  obj->addNum(3);
  obj->addNum(6);
  obj->addNum(6);
  obj->addNum(1);
  obj->addNum(2);
  double param_2 = obj->findMedian();
  std::cout << param_2 << std::endl;
  return 0;
}
