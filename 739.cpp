#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    auto sz = temperatures.size();

#ifdef ans1
    vector<int> ans;
    // decltype(sz) last_first_big_idx = sz;
    // for (auto i = 0; i < sz; i++) {
    //   auto j = i + 1;
    // here:
    //   while (j < last_first_big_idx && temperatures[j] <= temperatures[i]) {
    //     j++;
    //   }
    //   /* 如果中间有更大的数字 */
    //   if (j <= last_first_big_idx)
    //     ans.push_back(j == sz ? 0 : j - i);
    //   /* 如果自己足够大 则 retry */
    //   else if (last_first_big_idx == i) {
    //     last_first_big_idx = sz;
    //     goto here;
    //   }

    //   last_first_big_idx = j;
    // }
#else
    vector<int> ans(sz, 0);
    stack<int> monoStack;
    for (auto i = 0; i != sz; i++) {
      while (monoStack.size() &&
             temperatures[monoStack.top()] < temperatures[i]) {
        auto &&top = monoStack.top();
        ans[top] = i - top;
        monoStack.pop();
      }
      monoStack.push(i);
    }

#endif
    return ans;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> tem{89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
  auto ret = s.dailyTemperatures(tem);
  for (auto &&i : ret) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
