#include <bits/stdc++.h>
#include <condition_variable>
#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<thread> threads;

  int flag = 1;

  mutex m;
  condition_variable cv;

  for (int i = 1; i <= n; i++) {
    threads.emplace_back(
        [&](int i) {
          unique_lock<mutex> lock(m);
          while (flag != i)
            cv.wait(lock);
          std::cout << i << std::endl;
          flag++;
          cv.notify_all();
        },
        i);
  }

  for (int i = 0; i < n; i++)
    threads[i].join();
}