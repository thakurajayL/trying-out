package main

import (
	"fmt"
)

func main() {
	ch := make(chan int) // Create a channel 

	//this will block 
	<-ch
	fmt.Println("Here")
}
