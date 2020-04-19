package main

import (
	"fmt"
)
func handleSlice(s []int , index int) {
	fmt.Println("Received slice = ",s)
	s[index] *= 2
	fmt.Println("After change the content at index = ",s)
}

func doubles(s int)  {
	 s *= 2
}

func doublePtr(s *int) {
	*s  *= 2
}

func main() {
	fmt.Println("Let's learn how to pass slice to function")
	nums := []int{1,2,5,3,9}
	fmt.Println("Before function call Numbers  ",nums)
	handleSlice(nums[:], 2)
	fmt.Println("After functino call Numbers  ",nums)
	p := 2
	doubles(p)
	fmt.Println("Number p = ", p)

	doublePtr(&p)
	fmt.Println("Number p = ", p)
}
