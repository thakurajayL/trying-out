package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("unknown")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	fmt.Println("File Opened")
}
