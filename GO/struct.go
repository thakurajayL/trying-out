package main

import (
	"fmt"
)

type  Student  struct {
	name string
	age  int
	class int
	boy  bool
}

func (t Student)  getage()  int  {
	return t.age
}

func main() {
	s1 := Student{"Ajay", 12, 5, true}
	fmt.Println(s1)
	fmt.Printf("%+v\n",s1) // i love it ..it prints field:value pattern
	fmt.Println(s1.name)

	s2 := Student{
		name: "Anshu",
		age: 5,
		class: 1,
		boy: false,
	}
	fmt.Printf("%+v\n",s2)

	s3 := Student{}
	fmt.Printf("%+v\n",s3)

	fmt.Println(s2.getage())

}
