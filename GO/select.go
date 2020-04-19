package main
import (
	"fmt"
)

func main() {
	ch1, ch2 := make(chan int), make(chan int)

	go func() {
		ch1 <- 11
	}()

	select {
	case val := <-ch1:
		fmt.Printf("Received %d from channel 1\n",val)
	case val := <-ch2:
		fmt.Printf("Received %d from channel 2\n",val)
	}
}
