#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

class Solution {
public:
  bool judgePoint24(vector<int> &cards) {
    auto len = cards.size();
    vector<double> double_cards(len, 0);

    for (int i = 0; i < len; i++) {
      double_cards[i] = cards[i];
    }
    return dfs(double_cards);
  }

  bool dfs(vector<double> &cards) {
    auto len = cards.size();
    if (len == 1) {
      return fabs(cards[0] - 24.0) < 1e-5;
    }
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (i == j)
          continue;
        vector<double> double_cards;
        for (int k = 0; k < len; k++) {
          if (i == k || j == k)
            continue;
          double_cards.push_back(cards[k]);
        }

        for (int m = 0; m < 4; m++) {
          double res = calculate(cards, i, j, m);
          double_cards.push_back(res);
          bool ret = dfs(double_cards);
          if (ret)
            return ret;
          double_cards.pop_back();
        }
      }
    }
    return false;
  }

private:
  double calculate(vector<double> &double_cards, int i, int j, int op) {
    switch (op) {
    case 0:
      return double_cards[i] + double_cards[j];
    case 1:
      return double_cards[i] - double_cards[j];
    case 2:
      return double_cards[i] * double_cards[j];
    case 3:
      return double_cards[i] / double_cards[j];
    default:
      exit(1);
    }
  }
};

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{4, 1, 8, 7};
  EXPECT_EQ(s.judgePoint24(v), true);
}
