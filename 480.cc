#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
/* g++ x.cpp -lgtest -lgtest_main */

/*
删除一个数字
增添一个数字

如果删除的数字是小 如果增加的数字是大
中位数偏向大

如果删除的数字是大 如果增加的数字是小
中位数偏向小

 */

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> ret;
    int lens = nums.size();
    if (k == 1) {
      for (int i = 0; i < lens; i++) {
        ret.push_back(nums[i]);
      }
      return ret;
    }

    for (int i = 0; i < k; i++) {
      sets.insert({nums[i], i});
    }
    auto iter = sets.begin();

    /* init */
    for (int i = 0; i < k / 2 - 1; i++)
      iter++;

    if (k % 2) {
      mid = ++iter;
      ret.push_back(mid->first);
    } else {
      left = iter;
      right = ++iter;
      ret.push_back((right->first - left->first) / 2.0 + left->first);
    }

    /* window slid */
    for (int i = k; i < lens; i++) {
      int eras = nums[i - k];
      int inser = nums[i];
      auto eras_iter = sets.find({eras, i - k});
      auto inser_iter = sets.insert({inser, i});
      if (k % 2) {
        /* ok */
        if (*eras_iter == *mid) {
          if (inser >= mid->first)
            mid++;
          else
            mid--;
        } else if (*eras_iter<*mid && * inser_iter> * mid) {
          mid++;
        } else if (*eras_iter > *mid && *inser_iter < *mid) {
          mid--;
        }
        ret.push_back(mid->first);
      } else {
        if (*eras_iter == *left) {
          if (*inser_iter > *left) {
            left++;
            if (*inser_iter > *right) {
              right++;
            }
          } else if (*inser_iter < *left) {
            left--;
          }
        } else if (*eras_iter == *right) {
          if (*inser_iter < *right) {
            right--;
            if (*inser_iter < *left) {
              left--;
            }
          } else if (*inser_iter > *right) {
            right++;
          }
        } else {
          if (*eras_iter < *left) {
            if (*inser_iter < *left) {
            } else if (*inser_iter > *right) {
              right++;
              left++;
            } else {
              /* e l i r x */
              left++;
            }
          } else if (*eras_iter > *right) {
            if (*inser_iter > *right) {
              /* l r e i  */
            } else if (*inser_iter < *left) {
              /* x i l r e */
              right--;
              left--;
            } else {
              /* x l i r e */
              right--;
            }
          } else {
            /* no happen */
          }
        }
        ret.push_back((right->first - left->first) / 2.0 + left->first);
      }
      sets.erase(eras_iter);
    }
    return ret;
  }
  multiset<pair<long, int>> sets;
  multiset<pair<long, int>>::iterator left, right, mid;
};
// class Solution {
// public:
//   vector<double> medianSlidingWindow(vector<int> &nums, int k) {
//     vector<double> ret;
//     int lens = nums.size();
//     if (k == 1) {
//       for (int i = 0; i < lens; i++) {
//         ret.push_back(nums[i]);
//       }
//       return ret;
//     }

//     sets.insert(nums.begin(), nums.begin() + k);
//     auto iter = sets.begin();
//     for (int i = 0; i < k / 2 - 1; i++)
//       iter++;
//     /* 如果 k 是奇数，中位数是中间那个 */
//     if (k % 2) {
//       mid = ++iter;
//       ret.push_back(*mid);
//     } else {
//       left = iter;
//       right = ++iter;
//       ret.push_back((*right - *left) / 2.0 + *left);
//     }
//     for (int i = k; i < lens; i++) {
//       int eras = nums[i - k];
//       int inser = nums[i];
//       auto eras_iter = sets.find(eras);

//       /* auto inser_iter = */ sets.insert(inser);

//       if (k % 2) {
//         if (eras_iter == mid) {
//           if (inser >= *mid)
//             mid++;
//           else
//             mid--;
//         } else if (eras < *mid && inser > *mid) {
//           mid++;
//         } else if (eras > *mid && inser < *mid) {
//           mid--;
//         }
//         ret.push_back(*mid);
//       } else {
//         /* 删左 */
//         if (eras_iter == left) {
//           if (inser >= *right) {
//             left++;
//             right++;
//           } else if (inser < *right && inser > *left) {
//             left++;
//           } else if (inser == *left) {
//             left++;
//           } else if (inser < *left) {
//             left--;
//           }

//         } else if (eras_iter == right) {
//           if (inser >= *right) {
//             right++;
//           } else if (inser < *right && inser > *left) {
//             right--;
//           } else if (inser == *left) {
//             right--;
//           } else if (inser < *left) {
//             left--;
//             right--;
//           }
//         } else {
//           if (inser <= *left && eras >= *right) {
//             if (inser < *left)
//               left--;
//             right--;
//           } else if (inser >= *right && eras <= *left) {
//             left++;
//             right++;
//           } else if (eras <= *left && inser > *left && inser <= *right) {
//             if (inser == *right)
//               right++;
//             left++;
//           } else if (eras >= *right && inser >= *left && inser < *right) {
//             if (inser == *left)
//               left--;
//             right--;
//           }
//         }
//         ret.push_back((*right - *left) / 2.0 + *left);
//       }

//       if (eras_iter != sets.end())
//         sets.erase(eras_iter);
//     }

//     return ret;
//   }
//   multiset<int> sets;
//   multiset<int>::iterator left, right, mid;
// };

TEST(Solution, isMatch) {
  Solution s;
  vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  auto ret = s.medianSlidingWindow(v, 3);
  EXPECT_EQ(ret.size(), 6);
  vector<int> expect{1, -1, -1, 3, 5, 6};
  for (int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(expect[i], ret[i]);
  }
}

TEST(Solution, isMatch2) {
  Solution s;
  vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  auto ret = s.medianSlidingWindow(v, 4);
  EXPECT_EQ(ret.size(), 5);
  vector<double> expect{0, 1, 1, 4, 5.5};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}

TEST(Solution, isMatch3) {
  Solution s;
  vector<int> v{1, 1, 1, 1};
  auto ret = s.medianSlidingWindow(v, 2);
  EXPECT_EQ(ret.size(), 3);
  vector<double> expect{1, 1, 1};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}

TEST(Solution, isMatch4) {
  Solution s;
  vector<int> v{7, 9, 3, 8, 0, 2, 4, 8, 3, 9};
  auto ret = s.medianSlidingWindow(v, 1);
  EXPECT_EQ(ret.size(), 10);
  vector<double> expect{7, 9, 3, 8, 0, 2, 4, 8, 3, 9};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}

TEST(Solution, isMatch5) {
  Solution s;
  vector<int> v{5, 5, 8, 1, 4, 7, 1, 3, 8, 4};
  auto ret = s.medianSlidingWindow(v, 8);
  EXPECT_EQ(ret.size(), 3);
  vector<double> expect{4.5, 4.5, 4.0};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}
TEST(Solution, isMatch6) {
  Solution s;
  vector<int> v{6, 5, 9, 5, 4, 9, 1, 7, 5, 5};
  auto ret = s.medianSlidingWindow(v, 4);
  EXPECT_EQ(ret.size(), 7);
  vector<double> expect{5.50000, 5.00000, 7.00000, 4.50000,
                        5.50000, 6.00000, 5};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}
TEST(Solution, isMatch7) {
  Solution s;
  vector<int> v{4, 1, 7, 1, 8, 7, 8, 7, 7, 4};
  auto ret = s.medianSlidingWindow(v, 4);
  EXPECT_EQ(ret.size(), 7);
  vector<double> expect{2.5, 4.0, 7.0, 7.5, 7.5, 7.0, 7.0};
  for (int i = 0; i < ret.size(); i++)
    EXPECT_EQ(expect[i], ret[i]);
}