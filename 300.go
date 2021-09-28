package main

import (
	"fmt"
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

func lengthOfLIS(nums []int) int {
	lens := 0
	dp := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		dp[i] = 1
	}
	for i := 0; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				dp[i] = Max(dp[j]+1, dp[i])
			}
		}
	}

	for i := 0; i < len(nums); i++ {
		lens = Max(dp[i], lens)
	}
	return lens
}

func main() {

	ret := lengthOfLIS([]int{})
	fmt.Print(ret)
}
