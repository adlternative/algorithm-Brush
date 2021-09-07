package main

import (
	"fmt"
	// "log"
	// "log"
)

func minWindow(s string, t string) string {
	need := make(map[byte]int)
	have := make(map[byte]int)

	minLeft := 0
	minRight := len(s)
	minLen := len(s) + 1

	// lent := needLen
	lens := len(s)
	var left, right int

	for i := range t {
		need[t[i]]++
	}

	needLen := len(need)
	haveLen := 0
	// fmt.Println(needLen)
	for right < lens {
		/* 是需要的字符 */
		if needCnt, ok := need[s[right]]; ok {
			/* 我们已经拥有的字符 */
			have[s[right]]++
			haveCnt, _ := have[s[right]]
			/* 如果该字符的数量不够 */
			// log.Println(right, have, needCnt)
			if haveCnt == needCnt {
				haveLen++
			}

		}
		right++

		/* 全部匹配 */
		for haveLen == needLen {
			/* 如果更小则记录 */
			// log.Print(right, left)
			if right-left < minLen {
				minLen = right - left
				minLeft = left
				minRight = right
			}

			// log.Print(left, right, need)
			temp := left
			left++

			/* 如果该字符有用到  则减小数量 */
			if _, ok := need[s[temp]]; ok {
				have[s[temp]]--
				if have[s[temp]] < need[s[temp]] {
					haveLen--
					break
				}
			}
		}
	}
	if minLeft == minRight || minLen == len(s)+1 {
		return ""
	}
	return s[minLeft:minRight]
}

func main() {
	s := "ADOBECODEBANC"
	t := "ABC"
	fmt.Print(minWindow(s, t))
}
