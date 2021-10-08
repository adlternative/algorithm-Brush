package main

import (
	"fmt"
	_ "fmt"
)

func Max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestValidParentheses(s string) int {
	dp := make([]int, len(s))
	lens := len(s)
	stk := []int{}
	max := 0

	if lens <= 1 {
		return 0
	}
	for i := 0; i < lens; i++ {
		if s[i] == '(' {
			stk = append(stk, i)
		} else {
			if len(stk) != 0 {
				/* 可以产生合并 */
				index0 := stk[len(stk)-1]
				/* 弹栈 */
				stk = stk[:len(stk)-1]
				value := 0

				if index0-1 >= 0 && dp[index0-1] > 0 {
					value = dp[index0-1]
				}
				dp[i] = i - index0 + 1 + value
				max = Max(dp[i], max)
			}
		}
	}
	fmt.Println(dp)
	return max
}

func main() {
	ret := longestValidParentheses("(")
	fmt.Print(ret)
}
