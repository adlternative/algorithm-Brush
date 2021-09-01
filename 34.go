package main

import (
	"fmt"
)

func _searchRange(nums []int, left, right, target int) []int {
	if left > right {
		return []int{-1, -1}
	}

	mid := (right-left+1)/2 + left
	if nums[mid] > target {
		return _searchRange(nums, left, mid-1, target)
	} else if nums[mid] < target {
		return _searchRange(nums, mid+1, right, target)
	} else {
		ret := []int{}
		i := mid
		for ; i >= left; i-- {
			if nums[i] != target {
				// ret = append(ret, i+1)
				break
			}
		}
		// if i == left-1 {
		ret = append(ret, i+1)
		// }
		i = mid
		for ; i <= right; i++ {
			if nums[i] != target {
				// ret = append(ret, i-1)
				break
			}
		}
		ret = append(ret, i-1)

		return ret
	}
}

func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	return _searchRange(nums, 0, len(nums)-1, target)
}

func main() {
	nums := []int{5, 7, 7, 8, 8, 10}
	target := 8
	ret := searchRange(nums, target)
	fmt.Print(ret)
}
