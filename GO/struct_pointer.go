package main
import (
	"fmt"
	"log"
)

type Point struct {
	x int
	y int
}

type Square struct {
	Centre Point
	Length int 
}

func (p *Point) Move(x int, y int) {
	p.x += x
	p.y += y
}

func NewSquare(x int, y int, length int ) (* Square, error) {
	if length <=0 {
		return nil, fmt.Errorf("lengh must be >=0")
	}

	s := &Square{
		Centre: Point{x,y},
		Length: length,
	}
	return s, nil
}

func (s *Square) Move(dx int, dy int) {
	s.Centre.Move(dx,dy)
}

func(s *Square) Area() int {
	return s.Length * s.Length
}

func main() {
	s,err := NewSquare(1,1,10)
	if err != nil  {
		log.Fatalf("Error : Cant' create square")
	}
	fmt.Printf("%+v\n",s)
	s.Move(2,3)
	fmt.Printf("%+v\n",s)
	fmt.Println(s.Area())
}
