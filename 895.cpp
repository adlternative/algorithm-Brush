#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/*
map<int, int> 記錄數據的出現次數
vector<int> 記錄數據棧
priority_queue<int> 記錄頻率的次序
 */

class FreqStack {
public:
  unordered_map<int, vector<int>> vv; /* count -> vals[] */
  unordered_map<int, int> count;      /* val -> count */
  int max_ = INT_MIN;                 /* max count */
  FreqStack() = default;

  void push(int val) {
    int cnt = ++count[val];
    vv[cnt].push_back(val);
    max_ = max(max_, cnt);
  }

  int pop() {
    /* 最大值已經無了 -- */
    if (vv.count(max_) == 0 || vv[max_].size() == 0)
      max_--;
    int ret = vv[max_].back();
    vv[max_].pop_back();
    count[ret]--;
    return ret;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

TEST(Solution, isMatch) {
  FreqStack *obj = new FreqStack();
  vector<int> v{5, 7, 5, 7, 4, 5};
  for (int i = 0; i < v.size(); i++)
    obj->push(v[i]);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->pop(), 7);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->pop(), 4);
}
