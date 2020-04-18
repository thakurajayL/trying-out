// Lets try out some variables

package main

import (
	"fmt"
)

func main() {
	var x float64
	var y float64

	x = 1
	y = 20

	fmt.Printf("Varibale x = %v type=%T\n",x,x)
	fmt.Printf("Varibale y = %v type=%T\n",y,y)
	var mean float64
	mean = (x+y)/2
	fmt.Printf("Varibale Mean = %v\n",mean)

	a := 2  //new way of defining varibales 
	fmt.Printf("Varibale a = %v type=%T\n",a,a)

	p,q := 2,4  //multiple variabele assignments at the same time
	fmt.Printf("Varibale p = %v q = %v p-type=%T q-type=%T\n",p,q,p,q)

	//unused variables causes error... 
	// m := 2
}
