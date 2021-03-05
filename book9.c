//
// Created by adl on 2020/9/21.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} *list, node;

list creat_List() {
    list l = (list) malloc(sizeof(node));
    l->next = NULL;
    node *s, *r = l;//mv
    int x;
    scanf("%d", &x);
    while (x != -1) {
        s = (list) malloc(sizeof(node));
        s->val = x;
        r->next = s;
        r = s;
        printf("请输入下一结点的值：");
        scanf("%d", &x);
    }
    r->next = NULL;
    r = l->next;
    while (r != NULL) {
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return l;
}

void InsertAndDelete(list la, list lb, int i, int len, int j) {
    node *p1, *p2;
    node *t, *q;
    int sum = 1;
    int sum1 = 1;
    int len1 = len;
    p1 = la->next;
    p2 = lb->next;
    while (p1->next != NULL) {
        if (sum == i) {
            q = p1;
            t = p1->next;
            while (len1 >= 0) {
                q = q->next;
                len1--;
            }
            p1->next = q;
            break;
        }
        p1 = p1->next;
        sum++;
    }
    p1 = la->next;
    printf("第一个链表：");
    while (p1 != NULL) {
        printf("%d ", p1->val);
        p1 = p1->next;
    }
    printf("\n");
    len1 = len;
    while (p2->next != NULL) {
        if (sum1 == j) {
            q = p2->next;
            p2->next = t;
            while (len1 > 1) {
                t = t->next;
                len1--;
            }
            t->next = q;
            break;
        }
        p2 = p2->next;
        sum1++;
    }
    printf("\n");
    p2 = lb->next;
    printf("第二个链表：");
    while (p2 != NULL) {
        printf("%d ", p2->val);
        p2 = p2->next;
    }
    printf("\n");
}

int main() {
    list la, lb;
    int i;
    int len;
    int j;
//    printf("创建第一个链表！");
    la = creat_List();
//    printf("创建第二个链表！");
    lb = creat_List();
//    printf("请输入i，len，j的值！");
    scanf("%d %d %d", &i, &len, &j);
    InsertAndDelete(la, lb, i, len, j);
}