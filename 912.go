package main

import (
	"fmt"
	"math/rand"
)

func sort(nums []int, left, right int) int {
	pivot := rand.Intn(right-left+1) + left
	/* 交换 nums[left],nums[picot]*/
	temp := nums[left]
	nums[left] = nums[pivot]
	nums[pivot] = temp
	/* pivotVal = 原来的 nums[pivot] */
	pivotVal := nums[left]

	for left < right {
		/* 找右边小于基准值的 */
		for left < right && nums[right] >= pivotVal {
			right--
		}
		/* 将 right 放到左边 */
		nums[left] = nums[right]
		/* 找左边大于基准值的 */
		for left < right && nums[left] <= pivotVal {
			left++
		}
		/* 将 left 放到左边 */
		nums[right] = nums[left]
	}
	nums[left] = pivotVal
	return left
}

func quickSort(nums []int, left, right int) {
	if left >= right {
		return
	}
	mid := sort(nums, left, right)
	quickSort(nums, left, mid-1)
	quickSort(nums, mid+1, right)
}

func sortArray(nums []int) []int {
	quickSort(nums, 0, len(nums)-1)
	return nums
}

func main() {

	ret := sortArray([]int{5, 2, 3, 1})
	fmt.Print(ret)
}
