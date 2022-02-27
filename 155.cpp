#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class MinStack {
  stack<int> s1;
  stack<int> s2;

public:
  MinStack() { s2.push(INT_MAX); }

  void push(int val) {
    s1.push(val);
    auto top = s2.top();
    s2.push(val < top ? val : top);
  }

  void pop() {
    s1.pop();
    s2.pop();
  }

  int top() { return s1.top(); }

  int getMin() { return s2.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
