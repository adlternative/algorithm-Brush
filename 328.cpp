//
// Created by adl on 2020/11/13.
//

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* 0 1 2 3 4 5 */
/* 0 2 4 1 3 5 */
class Solution {
public:

    ListNode *oddEvenList(ListNode *head) {
        /*head=nullptr||(head!=nullptr&&head->next==nullptr)*/

        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *ehead = nullptr;
        auto pre = head;/*pre =链表头*/
        auto cur = pre->next;/*cur =链表头后面那个1 */
        pre->next = cur->next;
        pre = cur->next;/*pre = 链表头后面那个的后面那个3*/
        ehead = cur;/*偶数头为cur*/
        cur->next = nullptr;/*cur->next置为null*/
        cur = pre->next;/*3后面的5*/
        auto ecur = ehead;

        while (cur) {
            auto tmp = pre;
            ecur->next = cur;/*1->5*/
            ecur = ecur->next;
            pre->next = cur->next;
            pre = cur->next;//nullptr
            cur->next = nullptr;
            if (pre == nullptr ) {
                pre = tmp;
                break;
            }
            cur = pre->next;

        }

        pre->next = ehead;
        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *root = new ListNode(2);
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(5);
    ListNode *a4 = new ListNode(6);
    ListNode *a5 = new ListNode(4);
    ListNode *a6 = new ListNode(7);
//    ListNode *a7 = new ListNode(8);

    root->next = a1;
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
//    a6->next = a7;

    auto root2 = s.oddEvenList(root);
    auto cur = root2;
    while (cur) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
    return 0;
}