#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
  string fixStr(const string &s) {
    int lens = s.size();
    if (lens <= 2)
      return string(s);

    string ret;
    char last_ch = s[0];
    int last_cnt = 0;
    int cnt = 1;
    for (int i = 1; i <= lens; i++) {
      if (i != lens && s[i] == last_ch) {
        cnt++;
      } else {
        if (cnt >= 2) {
          if (last_cnt == 2) {
            last_cnt = 1;
            ret.push_back(s[i - 1]);
          } else {
            last_cnt = 2;
            for (int j = 0; j < 2; j++)
              ret.push_back(s[i - 1]);
          }
        } else {
          last_cnt = 1;
          ret.push_back(s[i - 1]);
        }
        last_ch = s[i];
        cnt = 1;
      }
    }
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  while (n--) {
    string str;
    cin >> str;
    cout << s.fixStr(str) << endl;
  }
}