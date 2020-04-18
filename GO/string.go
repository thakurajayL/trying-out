package main

import (
	"fmt"
)

func main() {
	name:= "Go Programming"
	fmt.Println(name)
	fmt.Println(len(name))
	fmt.Printf("name[0] = %v  (type %T)\n",name[0], name[0])
	// strings in go are immutable 
	// name[0] =  33 // cannot assign to name[0]
	fmt.Println(name[1:10]) // does not include name[10]
	fmt.Println(name[:3])
	fmt.Println(name[3:])
	fmt.Println("C++ to " + name[:3])
	fmt.Println("1/2  price") // TODO learn how to print unicode 
	//multi line
	message := `
	I am trying to add multiline string in the Go
	Let's see if this works`
	fmt.Println(message)
}
