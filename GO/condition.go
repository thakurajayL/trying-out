//using conditions operator

package main

import (
	"fmt"
)

func main() {
	x := 10
	if x > 3 {
		fmt.Printf("x is bigger than %v\n",x)
	}
	if x > 100 {
		fmt.Printf("x is very big \n")
	} else  {
		fmt.Printf("x is not that big \n")
	}
	if x > 5 &&  x<15  {
		fmt.Println("x is just right")
	}
	if x <20 ||  x > 30  {
		fmt.Println("x is out of range ")
	}
	a:= 11.0
	b:= 20.0
	if frac := a/b; frac > 0.5  {
		fmt.Println("a is more than half of b");
	}
}
