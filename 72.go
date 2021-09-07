package main

import (
	"fmt"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minDistance(word1 string, word2 string) int {
	len1 := len(word1)
	len2 := len(word2)

	dp := make([][]int, len1+1)
	for i := 0; i < len1+1; i++ {
		dp[i] = make([]int, len2+1)
		dp[i][0] = i
	}
	for i := 0; i < len2+1; i++ {
		dp[0][i] = i
	}
	for i := 1; i < len1+1; i++ {
		for j := 1; j < len2+1; j++ {
			if word1[i-1] != word2[j-1] {
				dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1
			} else {
				dp[i][j] = dp[i-1][j-1]
			}
		}
	}
	return dp[len1][len2]
}

func main() {

	ret := minDistance("horse", "ros")
	fmt.Print(ret)
}
