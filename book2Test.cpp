//
// Created by adl on 2020/9/21.
//

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>
#include"book2.h"

using namespace std;

int main(int argc, char *argv[]) {
    P p1;
    p1.build(4);
    p1.print();
    cout << "p1(3)= " << p1.value(3) << endl;
    p1.derivative()->print();
    P p2;
    p2.build(4);
    p2.print();
    auto p3 = p1 + p2;
    p3->print();
    auto p4 = p1 - p2;
    p4->print();
    return 0;
}