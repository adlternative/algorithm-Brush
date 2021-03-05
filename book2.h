//
// Created by adl on 2020/9/21.
//

#ifndef LUOGU_BOOK2_H
#define LUOGU_BOOK2_H


struct book2 {
    int p;

    book2(int p, int index);

    int index;
    book2 *next;
    book2 *prev;
};

struct P {
    book2 *head;
    book2 *tail;
    int x;
    P(/*int x*/);
    void print();
    P* operator+(const P&p1);
    P* operator-(const P&p1);
    void build(int n);
    void insert(int p,int i);
    int value(int x);
    P* derivative();
    int num;
};


#endif //LUOGU_BOOK2_H
