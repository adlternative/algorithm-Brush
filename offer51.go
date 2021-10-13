package main

import (
	"fmt"
)

func mergee(a []int, b []int) ([]int, int) {
	ret := []int{}
	sum := 0
	// len1 := len(a)
	// len2 := len(b)

	for len(a) > 0 && len(b) > 0 {
		if a[0] > b[0] {
			/* 我们在添加 b (右边的数据)的时候，可以找到逆序 */
			ret = append(ret, b[0])
			b = b[1:]
			sum += len(a)
		} else {
			ret = append(ret, a[0])
			a = a[1:]
		}
	}

	if len(a) > 0 {
		/* 逆序是0 */
		ret = append(ret, a...)
	} else {
		/* 逆序是0 */
		ret = append(ret, b...)
	}
	return ret, sum
}

func mergeSort(nums []int) ([]int, int) {
	lens := len(nums)
	if nums == nil || lens <= 1 {
		return nums, 0
	}
	sum := 0
	block1, cnt1 := mergeSort(nums[:lens/2]) /* len=2 [0:1) len=3 [0:1) len=4 [0:2)*/
	block2, cnt2 := mergeSort(nums[lens/2:]) /* len=2 [1:) len=3 [1:)  len=4 [2:)*/
	ret, sum := mergee(block1, block2)
	sum += cnt1
	sum += cnt2
	return ret, sum
}

func reversePairs(nums []int) int {
	_, ret := mergeSort(nums)
	return ret
}

func main() {
	ret := reversePairs([]int{7,5,6,4})
	fmt.Print(ret)
}
