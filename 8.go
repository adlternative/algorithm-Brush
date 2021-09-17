package main

import (
	"fmt"
	"strings"
)

const MaxUint = ^uint(0)
const MinUint = 0
const MaxInt = int(MaxUint >> 1)
const maxInt int64 = 1 << 31
const MinInt = -MaxInt - 1

func myAtoi(s string) int {
	/* 前导空格 */
	/* 前导 +/- */
	/* 前导字符 */
	/* 后导字符 */
	var ret int64
	reverse := false
	maxFlag := false

	s = strings.TrimSpace(s)
	if len(s) == 0 {
		return 0
	}

	if s[0] == '-' {
		reverse = true
	}
	if len(s) >= 2 && ((s[0] == '+' && s[1] == '-') || (s[0] == '-' && s[1] == '+') || (s[0] == '+' && s[1] == '+') || (s[0] == '-' && s[1] == '-')) {
		return 0
	}
	s = strings.TrimLeft(s, "+")
	s = strings.TrimLeft(s, "-")

	/* 4193 */
	for i := 0; i < len(s); i++ {
		val := int64(s[i] - '0')
		if s[i] < '0' || s[i] > '9' {
			break
		} else {
			if int64(ret*10+val) < maxInt {
				ret *= 10
			} else {
				maxFlag = true
				break
			}
		}
		ret += val
	}

	if maxFlag {
		if reverse {
			return -int(maxInt)
		} else {
			return int(maxInt) - 1
		}
	} else {
		if reverse {
			return int(-ret)
		} else {
			return int(ret)
		}
	}
}

func main() {
	ret := myAtoi("+-12")
	fmt.Println(ret)
}
