package main

import (
	"fmt"
	"sort"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func travel(root *TreeNode, m map[int]int, level int) {
	if root == nil {
		return
	}

	travel(root.Right, m, level+1)
	if _, ok := m[level]; !ok {
		m[level] = root.Val
	}
	travel(root.Left, m, level+1)
}

func rightSideView(root *TreeNode) []int {
	m := make(map[int]int) /* level to Val */
	ret := []int{}
	keys := []int{}

	travel(root, m, 0)
	for k, _ := range m {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	for _, k := range keys {
		ret = append(ret, m[k])
	}
	return ret
}

func main() {
	tree := &TreeNode{1, &TreeNode{2, &TreeNode{4, nil, nil}, &TreeNode{5, nil, nil}}, &TreeNode{3, nil, nil}}
	ret := rightSideView(tree)
	fmt.Print(ret)
}
