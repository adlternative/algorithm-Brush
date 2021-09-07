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

const (
	INT_MAX = int(^uint(0) >> 1)
)

func mergeKLists(lists []*ListNode) *ListNode {
	dummy := &ListNode{}
	cur := dummy
	lens := len(lists)
	if lens == 0 {
		return nil
	}
	cursors := make([]*ListNode, lens)
	for i := 0; i < lens; i++ {
		cursors[i] = lists[i]
	}

	for {
		var minIndex int
		down := true
		min := INT_MAX
		for i := 0; i < lens; i++ {
			if cursors[i] != nil {
				down = false
				if cursors[i].Val < min {
					min = cursors[i].Val
					minIndex = i
				}
			}
		}
		if down {
			cur.Next = nil
			break
		}

		cur.Next = cursors[minIndex]
		cur = cur.Next
		cursors[minIndex] = cursors[minIndex].Next
	}
	return dummy.Next
}

func main() {
	cursors := make([]*ListNode, 3)

	cursors[0] = &ListNode{1, &ListNode{4, &ListNode{5, nil}}}
	cursors[1] = &ListNode{1, &ListNode{3, &ListNode{4, nil}}}
	cursors[2] = &ListNode{2, &ListNode{6, nil}}

	ret := mergeKLists(cursors)
	fmt.Print(ret)
}
