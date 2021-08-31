package main

import (
	"fmt"
)

func longestPalindrome(s string) string {
	length := len(s)
	var max int
	var maxi, maxj int
	if length == 0 {
		return ""
	}
	dp := make([][]bool, length)

	for i := 0; i < length; i++ {
		dp[i] = make([]bool, length)
		dp[i][i] = true
		if dp[i][i] && 1 > max {
			max = 1
			maxi = i
			maxj = i
		}
	}

	for i := 0; i < length-1; i++ {
		dp[i][i+1] = dp[i][i] && s[i] == s[i+1]
		if dp[i][i+1] && 2 > max {
			max = 2
			maxi = i
			maxj = i + 1
		}
	}

	for i := length - 2; i >= 0; i-- {
		for j := i + 2; j < length; j++ {
			dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
			if dp[i][j] && j-i+1 > max {
				max = j - i + 1
				maxi = i
				maxj = j
			}
		}
	}

	// for i := 0; i < length; i++ {
	// 	fmt.Println(dp[i])
	// }

	// fmt.Print(maxi, maxj)
	return s[maxi : maxj+1]
}

func main() {

	ret := longestPalindrome("ac")
	fmt.Print(ret)
}
