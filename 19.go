package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) String() string {
	s := ""
	for l != nil {
		s += fmt.Sprintf("%v->", l.Val)
		l = l.Next
	}
	return s
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	window := []*ListNode{}
	dummy := &ListNode{Next: head}

	cur := dummy
	for i := 0; i < n+1; i++ {
		window = append(window, cur)
		cur = cur.Next
		if cur == nil && i != n {
			return nil
		}
	}

	for cur != nil {
		window = window[1:]
		window = append(window, cur)
		cur = cur.Next
	}
	window[0].Next = window[1].Next
	return dummy.Next
}
func main() {
	lists := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	ret := removeNthFromEnd(lists, 5)
	fmt.Print(ret)
}
