package main
import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int)

	go func() {
		for i:=10; i<13; i++ {
			fmt.Printf("Sending %d\n",i)
			ch<-i
			time.Sleep(time.Second)
		}
		close(ch)
	}()

	for i:= range ch {
		fmt.Printf("Received %d\n",i)
	}
}
