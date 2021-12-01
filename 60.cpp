#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/*
12345
12354
12435
12453
12534
12543
13xxx
*/

class Solution {
public:
  string getPermutation(int n, int k) {
    priority_queue<int, vector<int>> pq;
    set<int> s;
    string ans;
    int sum = 1;
    k--;
    pq.push(sum);
    for (int i = 1; i < n; i++) {
      sum *= i;
      pq.push(sum);
      s.insert(i);
    }
    s.insert(n);

    while (!pq.empty()) {
      auto i = pq.top();
      pq.pop();
      auto d = k / i;
      auto r = k % i;
      for (auto iter = s.begin(); iter != s.end(); ++iter, --d) {
        if (!d) {
          ans.push_back('0' + *iter);
          s.erase(iter);
          break;
        }
      }
      k = r;
    }
    return ans;
  }
};

TEST(Solution, isMatch) {
  Solution s;
  EXPECT_EQ(s.getPermutation(4, 9), "2314");
  EXPECT_EQ(s.getPermutation(3, 1), "123");
  EXPECT_EQ(s.getPermutation(1, 1), "1");
}
