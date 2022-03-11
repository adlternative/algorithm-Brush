#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  void qSort(vector<int> &nums, int begin, int end) {
    int lens = end - begin + 1;
    if (lens <= 1)
      return;

    int sentinel_index = begin + rand() % lens;
    swap(nums[begin], nums[sentinel_index]);
    int pivot = nums[begin];
    int l = begin, r = end;
    while (l < r) {
      while (l < r && nums[r] >= pivot)
        r--;
      while (l < r && nums[l] <= pivot)
        l++;
      swap(nums[l], nums[r]);
    }
    swap(nums[begin], nums[l]);
    qSort(nums, begin, l - 1);
    qSort(nums, l + 1, end);
  }
  // void qSort(vector<int> &nums, int begin, int end) {
  //   int lens = end - begin + 1;
  //   if (lens <= 1)
  //     return;

  //   int sentinel_index = begin + rand() % lens;
  //   swap(nums[begin], nums[sentinel_index]);
  //   int pivot = nums[begin];
  //   int l = begin, r = end;
  //   while (l < r) {
  //     while (l < r && nums[r] >= pivot)
  //       r--;
  //     nums[l] = nums[r];
  //     while (l < r && nums[l] <= pivot)
  //       l++;
  //     nums[r] = nums[l];
  //   }
  //   nums[l] = pivot;
  //   qSort(nums, begin, l - 1);
  //   qSort(nums, l + 1, end);
  // }

  vector<int> sortArray(vector<int> &nums) {
    srand(time(NULL));
    qSort(nums, 0, nums.size() - 1);
    return nums;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{5, 1, 1, 2, 0, 0};
  vector<int> expect{0, 0, 1, 1, 2, 5};
  auto ret = s.sortArray(v);
  for (int i = 0; i < v.size(); i++) {
    //   EXPECT_EQ(ret[i], expect[i]);
    std::cout << ret[i] << " ";
  }
  std::cout << std::endl;
}
