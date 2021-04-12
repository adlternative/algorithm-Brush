#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
class Solution {
public:
  map<int, int> ntof;
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> ret;
    for (auto &&i : nums) {
      ntof[i]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto &&i : ntof) {
      pq.push({i.second, i.first});
    }
    for (size_t i = 0; i < k; i++) {
      ret.push_back(pq.top().second);
      pq.pop();
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v{1, 1, 1, 2, 2, 3};
  Solution s;
  auto vv = s.topKFrequent(v, 2);
  for (auto &&i : vv) {
    std::cout << i << std::endl;
  }

  return 0;
}
