package main

import (
	"fmt"
)


func main() {
	x := 10
	fmt.Printf("x is %v and type %T \n",x,x)
	s := fmt.Sprintf("%d",x)
	fmt.Printf("S is %v and type %T \n",s,s)
	fmt.Printf("S is %q and type %T \n",s,s)
}
