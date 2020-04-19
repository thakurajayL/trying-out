package main

import (
	"fmt"
)

func safeValue(vals []int , index int) int {
	defer func() {
		if err := recover(); err != nil {
			fmt.Printf("Error : %s\n",err)
		}
	}()
	return vals[index]
}
func main() {
	// user wrappers to unwrap untrusted code
	v := safeValue([]int{1,2,3}, 10)
	fmt.Println(v)
}
