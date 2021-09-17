package main

import (
	"fmt"
	_ "fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func (head *ListNode) String() string {
	s := ""
	for head != nil {
		s += fmt.Sprintf("%d", head.Val)
		head = head.Next
	}
	return s
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	cur1, cur2 := l1, l2
	/* 到一个 nil 就退出 */
	prev1 := &ListNode{}
	// prev2 := &ListNode{}
	extra := 0
	for cur1 != nil && cur2 != nil {
		prev1 = cur1
		// prev2 = cur2
		cur1.Val += cur2.Val + extra

		if cur1.Val >= 10 {
			extra = 1
			cur1.Val -= 10
		} else {
			extra = 0
		}
		cur1 = cur1.Next
		cur2 = cur2.Next
	}
	/* 如果 cur1 空了 把 cur2 接过来 */
	if cur1 == nil {
		prev1.Next = cur2
	} else {
		/* cur2 == nil */
		/* 前一条链本身就是ok的 */
	}

	for cur1 = prev1.Next; cur1 != nil; {
		prev1 = cur1
		cur1.Val += extra
		if cur1.Val >= 10 {
			extra = 1
			cur1.Val -= 10
		} else {
			extra = 0
		}
		cur1 = cur1.Next
	}
	if extra != 0 {
		prev1.Next = &ListNode{Val: 1}
	}
	return l1
}

func main() {
	list1 := &ListNode{1, &ListNode{2, &ListNode{3, nil}}}
	list2 := &ListNode{9, &ListNode{7, &ListNode{6, nil}}}
	ret := addTwoNumbers(list1, list2)
	fmt.Print(ret)
}
