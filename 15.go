package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	ret := [][]int{}
	sort.Ints(nums)
	i := 0
	var l,r int
	// fmt.Println(nums)
	if len(nums) == 0 {
		return ret
	}

	for i = 0; i < len(nums)-2; i++ {
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		l = i + 1
		r = len(nums) -1
		for r > l {
			// fmt.Println(i, l, r)
			sum := nums[i] + nums[l] + nums[r]
			if sum < 0 {
				l++
			} else if sum > 0 {
				r--
			} else {
				// fmt.Print("WHAT")
				ret = append(ret, []int{nums[i], nums[l], nums[r]})
				l++
				for l != r && nums[l] == nums[l-1] {
					l++
				}
			}
		}
	}

	return ret
}

func main() {
	ret := threeSum([]int{-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4})
	fmt.Print(ret)
}
