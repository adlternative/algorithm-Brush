#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <memory>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    const auto &vPtr = kv.find(key);
    /* 没找到 */
    if (vPtr == kv.end())
      return -1;
    /* 找到了则通过迭代器的索引找到
    并重新放到链表头 （删除再插入）*/
    auto kv = vPtr->second;
    int k = kv->first;
    int v = kv->second;
    l.erase(kv);
    l.push_front({k, v});
    vPtr->second = l.begin();
    return v;
  }
  void put(int key, int value) {

    // /* 找到了 修改就好 将值设到最大*/
    const auto &vPtr = kv.find(key);
    // /* 找到 */
    if (vPtr != kv.end()) {
      auto kv = vPtr->second;
      l.erase(kv);
      l.push_front({key, value});
      vPtr->second = l.begin();
      return;
    }

    /* 否则如果满了 */
    if (kv.size() == capacity_) {
      kv.erase(l.back().first);
      l.pop_back();
      l.push_front({key, value});
      kv[key] = l.begin();
    } else {
      l.push_front({key, value});
      kv[key] = l.begin();
    }
  }
  list<pair<int, int>> l; /* 时间升序链表 存放k,v */
  int capacity_;          /* 容量 */
  unordered_map<int, list<pair<int, int>>::iterator>
      kv; /* k->list::iter 负责get  O1*/
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[]) {
  /* code */
  LRUCache *lRUCache = new LRUCache(2);

  lRUCache->put(1, 1);                        // 缓存是 {1=1}
  lRUCache->put(2, 2);                        // 缓存是 {1=1, 2=2}×
  std::cout << lRUCache->get(1) << std::endl; // 返回 1
  lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  std::cout << lRUCache->get(2) << std::endl; // 返回 -1 (未找到)
  lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  std::cout << lRUCache->get(1) << std::endl; // 返回 -1 (未找到)
  std::cout << lRUCache->get(3) << std::endl; // 返回 3
  std::cout << lRUCache->get(4) << std::endl; // 返回 4
  return 0;
}
