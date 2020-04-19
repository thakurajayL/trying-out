package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int)
	go func() {
		for i:=0; i< 3; i++ {
			fmt.Printf("Sending value %d to channel\n",i)
			ch <- i
			time.Sleep(time.Second)
		}
	}()

	for i:=0; i<3;i++ {
		val := <-ch
		fmt.Printf("Received value %d from channel\n",val)
	}
}
