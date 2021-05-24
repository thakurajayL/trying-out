// Golang program to illustrate
// reflect.Elem() Function

package main

import (
	"fmt"
	"reflect"
)

type Book struct {
	Id      int
	Title   string
	Price   float32
	Authors []string
}

// Main function
func main() {
	book := Book{}
    book.Id= 5

	//use of Elem() method
	e := reflect.ValueOf(&book).Elem()

	for i := 0; i < e.NumField(); i++ {
		fmt.Printf("Kind %v \n", e.Kind())
		fmt.Printf("Type %v \n", e.Type())
		varName := e.Type().Field(i).Name
		varType := e.Type().Field(i).Type
		varValue := e.Field(i).Interface()
		fmt.Printf("%v %v %v\n", varName, varType, varValue)
	}
}
