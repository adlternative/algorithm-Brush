package main

import (
	"fmt"
)

func isInterleave(s1 string, s2 string, s3 string) bool {
	len1 := len(s1)
	len2 := len(s2)
	len3 := len(s3)
	if len1+len2 != len3 {
		return false
	}
	/* 初始化 */
	dp := make([][]bool, len1+1)
	for i := 0; i < len1+1; i++ {
		dp[i] = make([]bool, len2+1)
	}
	dp[0][0] = true
	for i := 1; i <= len1; i++ {
		dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]
	}
	for j := 1; j <= len2; j++ {
		dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1]
	}
	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1] || dp[i-1][j] && s1[i-1] == s3[i+j-1]
		}
	}
	return dp[len1][len2]
}

func main() {
	s1 := "aabcc"
	s2 := "dbbca"
	s3 := "aadbbbaccc"
	ret := isInterleave(s1, s2, s3)
	fmt.Print(ret)
}
