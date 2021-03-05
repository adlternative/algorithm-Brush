//
// Created by adl on 2020/11/25.
//

// promise example
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

void print_int(std::future<int> &fut) {
    int x = fut.get();
    std::cout << "value: " << x << '\n';
}

void someFunction(std::future<bool> &fut) {
    bool x;
    while ((x = fut.get()));
    std::cout << x << '\n';
}

int main() {
    std::promise<bool> prom;                      // create promise
    std::future<bool> fut = prom.get_future();    // engagement with future
    std::thread th1(someFunction, std::ref(fut));  // send future to new thread
    prom.set_value(true);                         // fulfill promise
    // (synchronizes with getting the future)
    th1.join();
    return 0;
}