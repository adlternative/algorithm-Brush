package main

import (
	"fmt"
	"strconv"
	"strings"
)

func compareBlock(block1 string, block2 string) int {
	block1 = strings.TrimLeft(block1, "0")
	block2 = strings.TrimLeft(block2, "0")
	i1, _ := strconv.Atoi(block1)
	i2, _ := strconv.Atoi(block2)
	diff := i1 - i2
	if diff < 0 {
		return -1
	} else if diff > 0 {
		return 1
	} else {
		return 0
	}
}

func compareVersion(version1 string, version2 string) int {
	var ret int
	strs1 := strings.Split(version1, ".")
	strs2 := strings.Split(version2, ".")
	len1 := len(strs1)
	len2 := len(strs2)
	// fmt.Print(strs1, strs2)
	for i := 0; i < len1 && i < len2; i++ {
		block_diff := compareBlock(strs1[i], strs2[i])
		if block_diff != 0 {
			return block_diff
		}
	}

	if len1 > len2 {
		for i := len2; i < len1; i++ {
			block_diff := compareBlock(strs1[i], "0")
			if block_diff != 0 {
				return block_diff
			}
		}
	} else if len1 < len2 {
		for i := len1; i < len2; i++ {
			block_diff := compareBlock("0", strs2[i])
			if block_diff != 0 {
				return block_diff
			}
		}
	} else {
		return ret
	}

	return ret
}

func main() {

	ret := compareVersion("1", "1.1")
	fmt.Print(ret)
}
