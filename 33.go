package main

import (
	"fmt"
	_ "fmt"
)

func binartSearch(nums []int, target int) int {
	if nums == nil || len(nums) == 0 || (len(nums) == 1 && target != nums[0]) {
		return -1
	}

	mid := len(nums) / 2
	if target < nums[mid] {
		return binartSearch(nums[:mid], target)
	} else if target > nums[mid] {
		ret := binartSearch(nums[mid+1:], target)
		if ret != -1 {
			ret += mid + 1
		}
		return ret
	} else {
		return mid
	}
}

func search(nums []int, target int) int {
	/* 选找中断点 */
	lens := len(nums)
	var pos int
	ret := 0
	i := 1
	for ; i < lens; i++ {
		if nums[i] < nums[i-1] {
			break
		}
	}
	if i == lens {
		pos = -1 /* 表示已经有序 */
	} else {
		pos = i /* 表示 [i,lens) 后有序，[0,i) 前有序 */
	}
	/* 二分查找 */
	if pos != -1 {
		if target > nums[lens-1] {
			ret = binartSearch(nums[:pos], target)
		} else if target < nums[lens-1] {
			ret = binartSearch(nums[pos:], target)
			if ret != -1 {
				ret += pos
			}
		} else {
			ret = lens - 1
		}
	} else {
		ret = binartSearch(nums, target)
	}
	return ret
}

func main() {
	nums := []int{1, 3, 5}
	target := 5
	ret := search(nums, target)
	fmt.Print(ret)
}
