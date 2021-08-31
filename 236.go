package main

import (
	"fmt"
	_ "fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// func SearchNode(root *TreeNode) []*TreeNode {

// }

func SearchNode(root *TreeNode, target *TreeNode) (bool, []*TreeNode) {
	// tracePath := []*TreeNode{}

	if root == target {
		return true, []*TreeNode{root}
	}

	if root.Left == nil && root.Right == nil {
		return false, []*TreeNode{}
	}

	if root.Left != nil {
		if ok, nodes := SearchNode(root.Left, target); ok {
			return true, append(nodes, root)
		}
	}
	if root.Right != nil {
		if ok, nodes := SearchNode(root.Right, target); ok {
			return true, append(nodes, root)
		}
	}
	return false, []*TreeNode{}
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	_, pnodes := SearchNode(root, p)
	_, qnodes := SearchNode(root, q)
	// for i := 0; i < len(pnodes); i++ {
	// 	fmt.Print(pnodes[i].Val)
	// }
	// fmt.Println("")
	// for i := 0; i < len(qnodes); i++ {
	// 	fmt.Print(qnodes[i].Val)
	// }
	// fmt.Println("")

	plen := len(pnodes)
	qlen := len(qnodes)
	minlen := plen
	if minlen > qlen {
		minlen = qlen
	}
	// fmt.Println(plen, qlen, minlen)
	for i := 1; i <= minlen; i++ {
		if pnodes[plen-i] != qnodes[qlen-i] {
			if minlen == qlen {
				return pnodes[plen-i+1]
			} else {
				return qnodes[qlen-i+1]
			}
		}
	}
	if minlen == qlen {
		return qnodes[0]
	} else {
		return pnodes[0]
	}
}

func BuildNodes(values ...interface) []*TreeNode {
	nodelen := len(values)
	nodes := make([]*TreeNode, nodelen)
	for i := nodelen - 1; i >= 0; i-- {
		val, ok := values[i].(int)
		if !ok {
			nodes[i] = nil
			continue
		}
		nodes[i].Val = val

		if i*2+1 < nodelen {
			nodes[i].Left = nodes[i*2+1]
		} else {
			nodes[i].Left = nil
		}
		if i*2+2 < nodelen {
			nodes[i].Right = nodes[i*2+2]
		} else {
			nodes[i].Right = nil
		}
	}
	return nodes
}

func main() {
	slice := []interface{3, 5, 1, 6, 2, 0, 8, nil, nil, 7, 4}
	// BuildNodes([]interface{ slice })
	// ret := ()
	// fmt.Print(ret)
}
