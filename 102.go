package main

import (
	// "fmt"
	_ "fmt"
	// "os"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	nodes := []*TreeNode{}
	ret := [][]int{}
	// var baseLevel int
	var curLevel int
	if root == nil {
		return ret
	}

	nodes = append(nodes, root)

	for len(nodes) != 0 {
		ret = append(ret, []int{})

		for _, node := range nodes {
			ret[curLevel] = append(ret[curLevel], node.Val)

			if node.Left != nil {
				nodes = append(nodes, node.Left)
			}
			if node.Right != nil {
				nodes = append(nodes, node.Right)
			}
			nodes = nodes[1:]
		}
		curLevel++
	}
	return ret
}

func main() {

	node1 := &TreeNode{15, nil, nil}
	node2 := &TreeNode{7, nil, nil}
	node3 := &TreeNode{20, node1, node2}

	levelOrder(node3)

}
