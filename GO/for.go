package main

import (
	"fmt"
)

func main() {
	for i:= 0; i<5; i++ {
		fmt.Println(i)
	}
	fmt.Println("--Lets try break--- \n")
	for i := 0; i < 10; i++ {
		if i > 2 {
			break
		}
		fmt.Println(i)
	}
	fmt.Println("Lets try continue\n")
	for i:=0;i<10; i++ {
		if i % 2 == 0 {
			continue
		}
		fmt.Println(i)
	}
	fmt.Println("for loop-just like while\n")
	i := 3
	for i > 0 {
		fmt.Println(i)
		i--
	}
	fmt.Println("Let's try while 0 kind of loop \n")
	i = 0
	for {
		if i > 5 {
			break
		}
		fmt.Println(i)
		i++
	}
}
