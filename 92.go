package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	var index int
	dummy := &ListNode{Next: head}
	var cur *ListNode = head
	var prev *ListNode = dummy
	left -= 1
	right -= 1
	for index < left {
		temp := cur
		cur = cur.Next
		prev = temp
		index++
	}
	beginPrev := prev
	begin := cur
	for index < right {
		temp := cur
		tempNext := cur.Next
		cur.Next = prev
		prev = temp
		cur = tempNext
		index++
	}
	endNext := cur.Next
	end := cur
	end.Next = prev
	begin.Next = endNext
	beginPrev.Next = end
	return dummy.Next
}

func main() {
	nodes := []ListNode{
		ListNode{1, nil},
		ListNode{2, nil},
		ListNode{3, nil},
		ListNode{4, nil},
		ListNode{5, nil},
	}
	nodes[0].Next = &nodes[1]
	nodes[1].Next = &nodes[2]
	nodes[2].Next = &nodes[3]
	nodes[3].Next = &nodes[4]
	head := reverseBetween(&nodes[0], 2, 4)
	for head != nil {
		fmt.Print(head.Val)
		head = head.Next
	}
}
