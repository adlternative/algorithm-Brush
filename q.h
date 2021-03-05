//
// Created by adl on 2020/10/2.
//

#ifndef LUOGU_Q_H
#define LUOGU_Q_H

#include <ostream>

class q {
public:
    q(int a);
    q(int a,int c);

public:
    q();

    virtual ~q();

    int getA() const;

    bool operator==(const q &rhs) const;

    bool operator!=(const q &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const q &q);

    int c;
    int a;
};


#endif //LUOGU_Q_H
