package main

import (
	"fmt"
	"math"
)
// error is built in type in GO
func sqrt(num float64) (float64, error) {
	if(num < 0) {
		return 0.0, fmt.Errorf("sqrt of megative value (%f)", num)
	}
	return math.Sqrt(num), nil // nil is nothing, NULL or None

}

func main() {
	s1, err := sqrt(2.0)
	if err != nil {
		fmt.Printf("Error : %s\n", err)
	} else {
		fmt.Println(s1)
	}

	s2, err := sqrt(-2.0)
	if err != nil {
		fmt.Printf("Error : %s\n", err)
	} else {
		fmt.Println(s2)
	}
}
