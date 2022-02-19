#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto iter = key2iter_.find(key);
    if (iter == key2iter_.end())
      return -1;
    kvs_.splice(kvs_.begin(), kvs_, iter->second);
    return iter->second->second;
  }

  void put(int key, int value) {
    auto iter = key2iter_.find(key);
    if (iter == key2iter_.end()) {
      if (key2iter_.size() == capacity_)
        pop();
      kvs_.emplace_front(key, value);
      key2iter_[key] = kvs_.begin();
    } else {
      iter->second->second = value;
      kvs_.splice(kvs_.begin(), kvs_, iter->second);
    }
  }

private:
  void pop() {
    auto &pai = kvs_.back();
    key2iter_.erase(pai.first);
    kvs_.pop_back();
  }

  list<pair<int, int>> kvs_;
  unordered_map<int, decltype(kvs_)::iterator> key2iter_;
  int capacity_;
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
