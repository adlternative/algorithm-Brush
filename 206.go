package main

import (
	"fmt"
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

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	dummy := &ListNode{Next: head}
	/* head.prev = dummy */
	cur := head
	prev := dummy

	headNext := head.Next
	head.Next = nil

	prev = cur
	cur = headNext

	for cur != nil {
		// log.Println(cur)
		temp := cur.Next
		cur.Next = prev
		prev = cur
		cur = temp
	}
	dummy.Next = prev
	return dummy.Next
}

func main() {
	head := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	ret := reverseList(head)
	fmt.Print(ret)
}
