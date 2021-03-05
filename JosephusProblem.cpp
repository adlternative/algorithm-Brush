//
// Created by adl on 2020/9/20.
//

#include<bits/stdc++.h>

using namespace std;

struct people {
    people(int index, int m) : index(index), m(m), next(nullptr), prev(nullptr) {
//        std::cout << index << " " << m << std::endl;
    }

    int index;
    int m;
    people *next;
    people *prev;
};

struct peoList {
    peoList(people *head) : head(head) {
        head->prev = head->next = head;
    }

    people *head;

};

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;

    int p =rand() % m;
    peoList list(new people(1, p>0?p:1));
    int x = 2;
    while (x <= n) {
         int p =rand() % m;
        people *newNode = new people(x,p>0?p:1);
        newNode->prev = list.head->prev;
        newNode->next = list.head->prev->next;
        list.head->prev->next = newNode;
        list.head->prev = newNode;
        x++;
    }

    people *cur = list.head;
    int k = m - 1;
    while (list.head->next != list.head) {
        while (k--)
            cur = cur->next;
        if (list.head == cur)
            list.head = cur->next;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        std::cout << cur->index << std::endl;
        k = cur->m - 1;
        auto temp = cur->next;
        free(cur);
        cur = temp;
    }
    std::cout << list.head->index << std::endl;
    free(list.head);


    return 0;
}