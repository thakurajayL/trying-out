package main

import (
	"fmt"
	"time"
)

func main() {
	out := make(chan float64)
	go func() {
		time.Sleep(300*time.Millisecond)
		out <- 3.14
	}()

	select {
	case val := <-out:
		fmt.Printf("got %f \n", val)
	case <-time.After(200*time.Millisecond):
		fmt.Println("timeout")
	}
}
