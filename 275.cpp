#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int lens = citations.size();
    int l = 0, r = lens - 1;
    int h = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (lens - mid >= citations[mid]) {
        h = max(h, citations[mid]);
        l = mid + 1;
      } else if (mid >= 1 && lens - mid >= citations[mid - 1]) {
        h = max(h, lens - mid);
        l = mid + 1;
      } else if (mid == 0) {
        h = max(h, lens - mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return h == -1 ? 0 : h;
  }
};

TEST(Solution, hIndex) {
  Solution s;
  vector<int> citations{0, 1, 3, 5, 6};
  EXPECT_EQ(s.hIndex(citations), 3);
  citations = {1, 2, 100};
  EXPECT_EQ(s.hIndex(citations), 2);
  citations = {1};
  EXPECT_EQ(s.hIndex(citations), 1);
  citations = {0};
  EXPECT_EQ(s.hIndex(citations), 0);
  citations = {100};
  EXPECT_EQ(s.hIndex(citations), 1);
}