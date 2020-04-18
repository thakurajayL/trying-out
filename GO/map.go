package main

import (
	"fmt"
)

func main() {
	name := map[string] int {
		"Ajay" : 39,
		"Anshu": 8,
		"Vishal": 40, // this is mandatory for multiline  
	}
	fmt.Println(name)
	fmt.Printf("Length of map %v\n",len(name))
	fmt.Printf("name[Ajay] = %v\n",name["Ajay"])
	fmt.Printf("name[Unknown] = %v\n",name["Unknown"]) // unknown keys are 0

	// to know if key is present or not and also get the value at the key do following
	value, ok := name["Unknown"]
	if !ok {
		fmt.Println("key not found")
	} else {
		fmt.Println("key found Value = ", value)
	}
	name["Unknown"] = 50
	fmt.Println(name)

	delete(name, "Unknown")
	fmt.Println(name)

	for key:= range name {
		fmt.Println(key)
	}

	for key,value :=  range name {
		fmt.Printf("%v -> %v \n",key,value)
	}
}
