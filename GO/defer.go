package main

import (
	"fmt"
)

func cleanup(s string) {
	fmt.Println("Freeing up -",s)
}

func worker() {
	defer cleanup("A") // these calls are made before exiting function 
	defer cleanup("B") // this is called before cleanup(A) 
	fmt.Println("Inside worker \n")
}

func main() {
	fmt.Println("Inside main \n");
	worker()
}
