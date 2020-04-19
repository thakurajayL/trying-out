package main

import (
	"fmt"
	"io"
	"os"
)

type Capper struct {
	wtr io.Writer
}

func (c *Capper) Write(p []byte) (n int, err error) {
	diff := byte('a' - 'A')
	fmt.Printf("%v %T\n",diff,diff)

	out := make([]byte, len(p))
	for i,c := range p {
		if c >= 'a' &&  c <= 'z' {
			c  -= diff //convert to captial only if letter 
		}
		out[i] = c
	}
	return c.wtr.Write(out)
}
func main() {
	c := &Capper{os.Stdout}
	fmt.Fprintln(c,"Hello How are you?")
}
