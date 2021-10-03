package main

import (
	"fmt"
	_ "fmt"
	_ "log"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (node *TreeNode) String() string {
	return fmt.Sprintf("%d", node.Val)
}

func _pathSum(root *TreeNode, targetSum int, ret *[][]int, sum int, stk []*TreeNode) {
	/* 首先直接加上当前节点的值 */
	sum += root.Val
	stk = append(stk, root)
	/* 如果是个叶节点 */
	if root.Left == nil && root.Right == nil {
		/* 计算总和 相等则加上*/
		if sum == targetSum {

			vals := []int{}
			for _, node := range stk {
				vals = append(vals, node.Val)
			}
			*ret = append(*ret, vals)
			// log.Printf("ret=%v", ret)

		} else {
			/* 不相等则 nothing to do... */
		}
	} else if root.Left == nil {
		_pathSum(root.Right, targetSum, ret, sum, stk)
	} else if root.Right == nil {
		_pathSum(root.Left, targetSum, ret, sum, stk)
	} else {
		_pathSum(root.Right, targetSum, ret, sum, stk)
		_pathSum(root.Left, targetSum, ret, sum, stk)
	}
	stk = stk[:len(stk)-1]

}

func pathSum(root *TreeNode, targetSum int) [][]int {
	ret := make([][]int, 0)
	if root != nil {
		_pathSum(root, targetSum, &ret, 0, []*TreeNode{})
	}
	return ret
}

func main() {
	root := &TreeNode{
		Val: 5,
		Left: &TreeNode{
			Val: 4,
			Left: &TreeNode{
				Val:   11,
				Left:  &TreeNode{Val: 7},
				Right: &TreeNode{Val: 2},
			},
		},
		Right: &TreeNode{
			Val:  8,
			Left: &TreeNode{Val: 13},
			Right: &TreeNode{
				Val:   4,
				Left:  &TreeNode{Val: 5},
				Right: &TreeNode{Val: 1},
			},
		},
	}
	ret := pathSum(root, 22)
	fmt.Print(ret)
}
