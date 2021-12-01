#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */
#define m2
#ifdef m1
#define m1
class Solution {
public:
  using PIS = pair<int, string>;
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> um;
    for (auto &word : words)
      um[word]++;

    vector<PIS> ans;
    for (auto &[key, value] : um)
      ans.push_back({value, key});

    auto cmp = [](const PIS &p1, const PIS &p2) {
      if (p1.first == p2.first)
        return p1.second < p2.second;
      return p1.first > p2.first;
    };
    /* 快速选择 */
    nth_element(ans.begin(), ans.begin() + k, ans.end(), cmp);
    sort(ans.begin(), ans.begin() + k, cmp);

    vector<string> res;
    for (auto i = 0; i < k; i++)
      res.push_back(ans[i].second);

    return res;
  }
};

#endif //

#ifdef m2
#define m2
class Solution {
public:
  struct Cmp {
    bool operator()(pair<int, string> &p1, pair<int, string> &p2) {
      if (p1.first == p2.first)
        return p1.second > p2.second;
      return p1.first < p2.first;
    };
  };
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> um;

    priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp> p;
    auto lens = words.size();
    vector<string> ans;

    for (auto i = 0; i < lens; i++) {
      if (um.find(words[i]) != um.end())
        um[words[i]]++;
      else
        um[words[i]] = 1;
    }
    for (auto &pa : um) {
      p.push({pa.second, pa.first});
    }

    while (k--) {
      auto &pa = p.top();
      ans.push_back(pa.second);
      p.pop();
    }
    return ans;
  }
};
#endif
TEST(priority_queue, t1) {
  struct Cmp {
    bool operator()(int p1, int p2) { return p1 < p2; };
  };

  priority_queue<int, deque<int>, greater<int>> pp;
  pp.push(3);
  pp.push(2);
  pp.push(1);
  vector<int> ans;
  while (!pp.empty()) {
    auto pa = pp.top();
    ans.push_back(pa);
    pp.pop();
  }
  EXPECT_EQ(ans[0], 1);
  EXPECT_EQ(ans[1], 2);
  EXPECT_EQ(ans[2], 3);
}

TEST(Solution, isMatch) {
  Solution s;
  vector<string> v{"i", "love", "leetcode", "i", "love", "coding"};
  auto result = s.topKFrequent(v, 3);
  EXPECT_EQ(result[0], "i");
  EXPECT_EQ(result[1], "love");
}
TEST(Solution, isMatch2) {
  Solution s;
  vector<string> v{"the", "day", "is",    "sunny", "the",
                   "the", "the", "sunny", "is",    "is"};
  auto result = s.topKFrequent(v, 4);

  EXPECT_EQ(result[0], "the");
  EXPECT_EQ(result[1], "is");
  EXPECT_EQ(result[2], "sunny");
  EXPECT_EQ(result[3], "day");
}