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

func reverseListK(head *ListNode, headPrev *ListNode, k int) (*ListNode, *ListNode, *ListNode) {
	// if head == nil || head.Next == nil {
	// 	return head
	// }
	index := 0
	cur := head

	if headPrev == nil {
		headPrev = &ListNode{Next: head}
	}

	headNext := head.Next
	prev := headPrev

	for cur != nil && index != k {
		prev = cur
		cur = cur.Next
		index++
	}
	if index != k {
		return head, prev, cur
	}

	prev = head
	cur = headNext
	index = 1

	for cur != nil && index != k {
		temp := cur.Next
		cur.Next = prev
		prev = cur
		cur = temp
		index++
	}

	head.Next = cur      /*  head.next = tail.next */
	headPrev.Next = prev /*  head.prev.next = tail*/

	/* 新的开头，新的结尾, 结尾的 next */
	return headPrev.Next, head, cur
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1 {
		return head
	}
	cur := head
	var prev *ListNode
	head, prev, cur = reverseListK(cur, prev, k)
	ret := head
	for cur != nil {
		head, prev, cur = reverseListK(cur, prev, k)
	}
	return ret
}

func main() {
	head := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	ret := reverseKGroup(head,4)
	fmt.Print(ret)
}
