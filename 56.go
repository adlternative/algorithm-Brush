package main

import (
	"fmt"
	"sort"
)

func Max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func Min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

type block [][]int

func (a block) Len() int           { return len(a) }
func (a block) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a block) Less(i, j int) bool { return a[i][0] < a[j][0] }

func merge(c block) [][]int {
	sort.Sort(c)
	ret := make([][]int, 0)
	for i := 0; i < len(c)-1; {
		j := i + 1
		if c[i][1] < c[j][0] {
			/* 不合并 */
			ret = append(ret, c[i])
		} else if c[i][1] >= c[j][0] && c[i][1] <= c[j][1] {
			/* 合并 */
			c[j] = []int{c[i][0], c[j][1]}
		} else if c[i][1] > c[j][1] {
			c[j] = c[i]
		}
		c = c[j:]
	}
	ret = append(ret, c[0])

	return ret
}

func main() {
	ret := merge([][]int{[]int{1, 3}, []int{2, 6}, []int{8, 10}, []int{15, 18}})
	fmt.Print(ret)
}
