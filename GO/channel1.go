package main

import (
	"fmt"
)

func main() {
	ch := make(chan int) // Create a channel 

	go func() {
		ch <- 100 // send number to channel
		ch <- 101 // send number to channel
	}()

	val := <-ch
	fmt.Println(val)
	val = <-ch
	fmt.Println(val)
}
