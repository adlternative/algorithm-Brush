#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxDiffCharSub(string_view s) {
  int lens = s.size();
  int ret = 0;
  /* abcbccde */
  int begin = 0, end = 0;
  unordered_map<char, int> c2idx;
  for (int i = 0; i < lens; i++) {
    auto iter = c2idx.find(s[i]);
    if (iter == c2idx.end()) {
      c2idx[s[i]] = i;
    } else {
      int old_index = iter->second;
      iter->second = i;
      ret = max(ret, end - begin);
      // 
      begin = old_index + 1;
    }
      end++;
  }
  ret = max(ret, end - begin);

  return ret;
}

int main() {
  string s;
  cin >> s;
  cout << maxDiffCharSub(s) << endl;
}