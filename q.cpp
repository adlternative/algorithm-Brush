//
// Created by adl on 2020/10/2.
//
#include <iostream>
#include "q.h"
#include <vector>
q::~q() {

}

q::q() {}

q::q(int a) : a(a) {}

int q::getA() const {
    return a;
}

bool q::operator==(const q &rhs) const {
    return a == rhs.a;
}

std::ostream &operator<<(std::ostream &os, const q &q) {
    os << "a: " << q.a;
    return os;
}

bool q::operator!=(const q &rhs) const {
    return !(rhs == *this);
}

q::q(int a, int c) {

}


int main(int argc,char*argv[])
{
    std::string s;
    std::vector<int>v;
    return 0;
}