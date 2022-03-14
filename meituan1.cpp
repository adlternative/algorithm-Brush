#include <bits/stdc++.h> /* 万能头 */
#include <iostream>
#include <string>

using namespace std;

bool haveOne(int v) {
  auto s = to_string(v);
  int count = 0;
  for (auto &c : s) {
    if (c == '1') {
      count++;
      if (count >= 2)
        return true;
    }
  }
  return false;
}

bool check(int v) { return (v % 11 == 0) || haveOne(v); }

int main(int argc, char **argv) {
  int n;
  cin >> n;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    cout << (check(v) ? "yes" : "no") << endl;
  }
}