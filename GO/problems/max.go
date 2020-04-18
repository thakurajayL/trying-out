package main

import (
	"fmt"
)

func main() {
	nums:= []int{16,8,9,34,21,15}
	fmt.Println("List of number",nums)
	max := nums[0]
	for _, i:= range nums[1:] {
		fmt.Println("num ", i)
		if(max < i) {
			max = i
		}
	}
	fmt.Println("maximum number ", max)
}
