package main

import (
	"fmt"
)

func minimumTotal(triangle [][]int) int {
	row := len(triangle)
	col := len(triangle[row-1])
	var ret int
	dp := make([][]int, row)
	for i := 0; i < row; i++ {
		dp[i] = make([]int, col)
	}
	for i := 0; i < row; i++ {
		if i == 0 {
			dp[i][0] = triangle[i][0]
		} else {
			dp[i][0] = dp[i-1][0] + triangle[i][0]
		}
	}

	for i := 1; i < row; i++ {
		for j := 1; j <= i; j++ {
			if j != i && dp[i-1][j] < dp[i-1][j-1] {
				dp[i][j] = dp[i-1][j] + triangle[i][j]
			} else {
				dp[i][j] = dp[i-1][j-1] + triangle[i][j]
			}
		}
	}
	ret = dp[row-1][0]
	for j := 1; j < col; j++ {
		if ret > dp[row-1][j] {
			ret = dp[row-1][j]
		}
	}
	return ret
}

func main() {
	triangle := [][]int{
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	}
	ret := minimumTotal(triangle)
	fmt.Print(ret)
}
