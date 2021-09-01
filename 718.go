package main

import (
	"fmt"
)

func findLength(nums1 []int, nums2 []int) int {
	len1 := len(nums1)
	len2 := len(nums2)
	var max int
	dp := make([][]int, len1)
	for i := 0; i < len1; i++ {
		dp[i] = make([]int, len2)
	}
	for i := len1 - 1; i >= 0; i-- {
		if nums1[i] == nums2[len2-1] {
			dp[i][len2-1] = 1
			if dp[i][len2-1] > max {
				max = dp[i][len2-1]
			}
		}
	}

	for i := len2 - 1; i >= 0; i-- {
		if nums2[i] == nums1[len1-1] {
			dp[len1-1][i] = 1
			if dp[len1-1][i] > max {
				max = dp[len1-1][i]
			}
		}
	}

	for i := len1 - 1; i >= 0; i-- {
		for j := len2 - 1; j >= 0; j-- {
			if i == len1-1 || j == len2-1 {
				continue
			}
			if nums1[i] == nums2[j] {
				dp[i][j] = dp[i+1][j+1] + 1
				if dp[i][j] > max {
					max = dp[i][j]
				}
			}
		}
	}
	return max
}

func main() {
	A := []int{1, 2, 3, 2, 1}
	B := []int{3, 2, 1, 4, 7}
	ret := findLength(A, B)
	fmt.Print(ret)
}
