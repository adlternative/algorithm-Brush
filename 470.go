package main

import (
	"fmt"
	_ "fmt"
	"math/rand"
)

func rand10() int {
	first, second := rand7(), rand7()
	for first > 6 {
		first = rand7()
		continue
	}
	for second > 5 {
		second = rand7()
		continue
	}
	if first%2 == 0 {
		return second
	} else {
		return second+5
	}

}

func rand7() int {
	return rand.Intn(7) + 1
}
func main() {
	count := make(map[int]int, 0)
	for i := 0; i < 10000000; i++ {
		ret := rand10()
		count[ret]++
	}
	fmt.Println(count)
}
