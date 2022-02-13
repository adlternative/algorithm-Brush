#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class Solution {
public:
  vector<int> nums_; /* 原始 */
  int lens_;
  Solution(vector<int> &nums) : nums_(nums), lens_(nums_.size()) {
    srand(time(NULL));
  }

  vector<int> reset() { return nums_; }

  vector<int> shuffle() {
    vector<int> ret(nums_);

    for (int i = 0; i < lens_ - 1; i++) {
      int index = rand() % (lens_ - i) + i;
      swap(ret[i], ret[index]);
    }
    return ret;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
TEST(Solution, isMatch) {
  vector<int> v{1, 2, 3};
  Solution s(v);
  auto ret = s.shuffle();
  for (int i = 0; i < ret.size(); i++) {
    std::cout << ret[i];
  }

  std::cout << std::endl;
}
