package main

import (
	"fmt"
	// "strings"
	// _ "fmt"
)

func reverseWords(s string) string {
	ret := ""
	strs := []string{}
	var beg, end = 0, len(s) - 1
	var wordBegin int
	if len(s) == 0 {
		return ret
	}
	for beg != end && s[beg] == ' ' {
		beg++
	}
	for end != beg && s[end] == ' ' {
		end--
	}
	if beg == end && s[end] == ' ' {
		return ret
	}
	wordBegin = beg
	for i := beg; i <= end; i++ {
		if s[i] == ' ' {
			strs = append(strs, s[wordBegin:i])
			for i <= end && s[i] == ' ' {
				i++
			}
			wordBegin = i
		}
	}
	// if len(strs) == 0 {
	// 	return ret
	// }

	strs = append(strs, s[wordBegin:end+1])

	for i := len(strs) - 1; i >= 1; i-- {
		ret += strs[i] + " "
	}
	ret += strs[0]

	return ret
}

func main() {
	ret := reverseWords("a")
	fmt.Print(ret)
}
