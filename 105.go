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

// (TreeNode*) {

// }

func _buildTree(preorder []int, inorder []int, pre, inLeft, inRight int) *TreeNode {
	rootVal := preorder[pre]
	root := &TreeNode{Val: rootVal}
	for i := inLeft; i <= inRight; i++ {
		if inorder[i] == rootVal {
			if inRight-inLeft == 0 {
				root.Left = nil
				root.Right = nil
			} else if i == inRight {
				root.Left = _buildTree(preorder, inorder, pre+1, inLeft, i-1)
				root.Right = nil
			} else if i == inLeft {
				root.Left = nil
				root.Right = _buildTree(preorder, inorder, pre+1, i+1, inRight)
			} else {
				root.Left = _buildTree(preorder, inorder, pre+1, inLeft, i-1)
				root.Right = _buildTree(preorder, inorder, pre+i-inLeft+1, i+1, inRight)
			}
		}
	}
	return root
}
func buildTree(preorder []int, inorder []int) *TreeNode {
	// rootVal := preorder[0]
	// root := &TreeNode{Val: rootVal}
	return _buildTree(preorder, inorder, 0, 0, len(inorder)-1)
}

func main() {
	preorder := []int{3, 9, 20, 15, 7}
	inorder := []int{9, 3, 15, 20, 7}
	buildTree(preorder, inorder)
	// fmt.Print()
}
