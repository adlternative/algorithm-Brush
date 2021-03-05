//
// Created by adl on 2020/9/21.
//

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "book2.h"


book2::book2(int p, int index) : p(p), index(index), next(nullptr), prev(nullptr) {}


void P::build(int n) {

    for (int i = 0; i != n; ++i) {
        insert(rand() % 10, i);
    }
}

P::P(/*int x*/) :/* x(x),*/ head(new book2(-1, -1)), tail(head), num(0) {

}

void P::print() {
    auto cur = head->next;
    if (cur != nullptr) {
        std::cout << cur->p << "*x^" << cur->index;
    }
    cur = cur->next;
    while (cur != nullptr) {
        std::cout << "+" << cur->p << "*x^" << cur->index;
        cur = cur->next;
    }
    std::cout << std::endl;


}

P *P::operator+(const P &p2) {
    auto c1 = head->next;
    auto c2 = p2.head->next;
    auto p3 = new P;
    while (c1 != nullptr && c2 != nullptr) {
        p3->insert(c1->p + c2->p, c1->index);
        c1 = c1->next;
        c2 = c2->next;
    }
    if (c1 == nullptr) {
        while (c2 != nullptr)
            p3->insert(c2->p, c2->index);
    } else {
        while (c1 != nullptr)
            p3->insert(c1->p, c1->index);
    }
    return p3;
}

void P::insert(int p, int i) {
    auto newNode = new book2(p, i);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    num++;

}

P *P::operator-(const P &p2) {
    auto c1 = head->next;
    auto c2 = p2.head->next;
    auto p3 = new P;
    while (c1 != nullptr && c2 != nullptr) {
        p3->insert(c1->p - c2->p, c1->index);
        c1 = c1->next;
        c2 = c2->next;
    }
    if (c1 == nullptr) {
        while (c2 != nullptr)
            p3->insert(-c2->p, c2->index);
    } else {
        while (c1 != nullptr)
            p3->insert(c1->p, c1->index);
    }
    return p3;
}

int P::value(int x) {
    auto cur = head->next;
    int num = 0;
    while (cur != nullptr) {
        num += cur->p * pow(x, cur->index) /*<< std::endl*/;
        cur = cur->next;
    }
    return num;
}

P *P::derivative() {
    auto p3 = new P;
    auto c1 = head->next;
    while (c1 != nullptr) {
        std::cout << ">>>" << std::endl;
        if (c1->next)
            p3->insert(c1->p * c1->next->index, c1->next->index - 1);
        std::cout << ">>>" << std::endl;
        c1 = c1->next;
    }
}
