package main

import (
	"fmt"
)

func main() {
	loons := []string{"bugs","daffy","taz"} // string array 	
	fmt.Printf("loons = %v (type %T)\n",loons, loons)
	fmt.Printf("Length of loons = %v\n",len(loons))
	fmt.Printf("1st element (start index 0) in loon %v\n",loons[1])
	fmt.Printf("Elements in loon from 1st index to end are %v\n",loons[1:])
	fmt.Printf("-----Let's use for loop -----")
	for i:=0;i<len(loons);i++ {
		fmt.Println(loons[i])
	}
	fmt.Printf("-----Let's use for range-----")
	for i:=  range loons {
		fmt.Println(loons[i])
	}
	//tuple like looping 
	fmt.Printf("-----Let's use key,val tyoe of looping -----")
	for i,name := range loons {
		fmt.Printf("%v : %v \n",i,name)
	}
	fmt.Printf("-----Let's use _,val tyoe of looping -----")
	for _,name := range loons {
		fmt.Printf(" %v \n",name)
	}
}
