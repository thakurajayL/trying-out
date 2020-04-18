package main

import (
	"fmt"
)

func main() {
	x := 11

	switch x {
	case 1:
		fmt.Println("x is 1\n")
	case 2:
		fmt.Println("x is 2\n")
	default:
		fmt.Println("default case \n")
	}

	switch {
	case x > 10:
		fmt.Println("x is bigger than 10")
	case x  > 100:
		fmt.Println("x is very big..bigger than 100")
	default:
		fmt.Println("x is small than 10")
	}
}
