#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <fmt/compile.h>
#include <fmt/core.h>
#include <sys/types.h>
#include <tuple>
#include <unistd.h>
using namespace std;
class Solution {
public:
  deque<int> singleVectorMaxNumber(vector<int> &nums1, int max_len) {
    deque<int> deq;
    auto remove_len = nums1.size() - max_len;
    for (auto &&num : nums1) {
      while (deq.size() && remove_len && num > deq[deq.size() - 1]) {
        deq.pop_back();
        remove_len--;
      }
      deq.push_back(num);
    }
    deq.resize(max_len);

    return std::move(deq);
  }
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> ret;

    auto len1 = nums1.size();
    auto len2 = nums2.size();

    for (int i = max(0, k - (int)len2); i <= len1 && i <= k; i++) {
      int j = k - i;
      deque<int> deq1;
      deque<int> deq2;
      if (i) {
        deq1 = singleVectorMaxNumber(nums1, i);
        // fmt::print("deq1={}\n", fmt::join(deq1, ", "));
      }
      if (j) {
        deq2 = singleVectorMaxNumber(nums2, j);
        // fmt::print("deq2={}\n", fmt::join(deq2, ", "));
      }
      ret = max(ret, merge(deq1, deq2));
      // fmt::print("ret ={}\n", fmt::join(ret, ", "));
    }
    return ret;
  }
  bool compare(deque<int> &d1, int cur1, deque<int> &d2, int cur2) {
    while (cur1 != d1.size() && cur2 != d2.size() && d1[cur1] == d2[cur2]) {
      cur1++;
      cur2++;
    }
    /* 说明对方更长，应该选对方 */
    if (cur1 == d1.size())
      return false;
    else if (cur2 == d2.size())
      return true;
    else {
      /* 说明有一者更大 我们拿大的*/
      return d1[cur1] > d2[cur2];
    }
  }
  vector<int> merge(deque<int> &deq1, deque<int> &deq2) {
    vector<int> ret;
    int len1 = deq1.size();
    int len2 = deq2.size();
    for (auto i = 0, j = 0; i < len1 || j < len2;) {
      if (i < len1 && j < len2) {
        if (deq1[i] > deq2[j])
          ret.push_back(deq1[i++]);
        else if (deq1[i] < deq2[j])
          ret.push_back(deq2[j++]);
        /* 如果都没有到头 */
        else {
          if (compare(deq1, i, deq2, j))
            ret.push_back(deq1[i++]);
          else
            ret.push_back(deq2[j++]);
          // while (i + 1 < len1 && j + 1 < len2) {
          //   if (deq1[i + 1] >= deq2[j + 1])
          //     ret.push_back(deq1[i++]);
          //   else
          //     ret.push_back(deq2[j++]);
          // } else if (i + 1 == len1) { /*  */
          //   ret.push_back(deq2[j++]);
          // } else if (j + 1 == len2) {
          //   ret.push_back(deq1[i++]);
          // } else
          //   ret.push_back(deq1[i++]);
        }
      } else if (i < len1)
        ret.push_back(deq1[i++]);
      else if (j < len2)
        ret.push_back(deq2[j++]);
    }
    // fmt::print("merge={}\n", fmt::join(ret, ", "));

    return std::move(ret);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> a{6, 3, 9, 0, 5, 6};
  vector<int> b{2, 2, 5, 2, 1, 4, 4, 5, 7, 8, 9, 3, 1, 6, 9, 7, 0};
  // auto vec = s.singleVectorMaxNumber(a, 1);
  // //fmt::print("{}", fmt::join(vec, ", "));

  auto vec = s.maxNumber(a, b, 23);
  fmt::print("{}", fmt::join(vec, ", "));

  return 0;
}
