#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class LRUCache {
public:
  LRUCache(int capacity) : cap_(capacity) {}

  int get(int key) {
    int ret;
    auto iter = k2iter.find(key);
    if (iter != k2iter.end()) {
      auto liter = iter->second;
      ret = liter->second;
      /* 将迭代器移动到链表开头 */
      cache.splice(cache.begin(), cache, liter);
    } else {
      ret = -1;
    }
    return ret;
  }

  void put(int key, int value) {
    auto iter = k2iter.find(key);
    if (iter != k2iter.end()) {
      auto liter = iter->second;
      liter->second = value;
      /* 将迭代器移动到链表开头 */
      cache.splice(cache.begin(), cache, liter);
    } else {
      cache.emplace_front(key, value);
      k2iter[key] = cache.begin();
    }
    pop();
  }

private:
  void pop() {
    while (k2iter.size() > cap_) {
      k2iter.erase(cache.back().first);
      cache.pop_back();
    }
  }

  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::iterator> k2iter;

  int cap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
TEST(Solution, isMatch) {
  // Solution s;
  // EXPECT_EQ(s.(), );
}
