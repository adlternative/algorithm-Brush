package main

import (
	_ "fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func _postorderTraversal(root *TreeNode, arr *[]int) {
	if root == nil {
		return
	}
	_postorderTraversal(root.Left, arr)
	_postorderTraversal(root.Right, arr)
	*arr = append(*arr, root.Val)
}

func postorderTraversal(root *TreeNode) []int {
	arr := []int{}
	_postorderTraversal(root, &arr)
	return arr
}

func main() {

	// ret := ()
	// fmt.Print(ret)
}
