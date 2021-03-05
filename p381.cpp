//
// Created by adl on 2020/10/31.
//

#include<bits/stdc++.h>

using namespace std;

class RandomizedCollection {

public:
    unordered_multimap<int, int> um;
//    vector<unordered_multimap<int, int>::iterator> v;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto ret = um.find(val) == um.end();
//        std::cout << val <<v.size()<< std::endl;
        auto iter = um.insert({val, val});
//        v.push_back(iter);
        return ret;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = um.find(val);
//        std::cout << it->second << std::endl;
        auto ret = false;
        if (it != um.end()) {
            ret = true;
//            int a = it->second;
//            v[a] = v.back();
//            v[a]->second=it->second;
//            v.pop_back();
            um.erase(it);
        }
        return ret;
    }

    /** Get a random element from the collection. */
    int getRandom() {
//        return v[rand() % v.size()]->first;
        auto i = rand() % um.size();
        auto it = um.begin();
        while (i--)
            it++;
        return it->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char *argv[]) {
    RandomizedCollection rc;
    rc.insert(1);
    rc.insert(1);
    rc.insert(2);
//    rc.insert(2);
    rc.remove(1);
    auto i_1 = 0;
    auto i_2 = 0;
    auto i_0 = 0;
    for (int i = 0; i != 1000; ++i) {
        auto r = rc.getRandom();
        if (r == 1) {
            i_1++;
        } else if (r == 2) {
            i_2++;
        } else if (r == 0) {
            i_0++;
        }
    }

    std::cout << i_0 << std::endl;
    std::cout << i_1 << std::endl;
    std::cout << i_2 << std::endl;
    return 0;
}
