package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	ret := []int{}
	for i := 0; i < len(nums); i++ {
		if v, ok := m[target-nums[i]]; ok {
			ret = append(ret, v, i)
		}
		m[nums[i]] = i
	}
	return ret
}

func main() {

	ret := twoSum([]int{2, 7, 11, 15}, 9)
	fmt.Print(ret)
}
