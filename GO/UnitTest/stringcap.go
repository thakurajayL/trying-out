package stringcap
import (
	"fmt"
)

func caps(name string) string {
	diff := byte('a' - 'A')
	fmt.Printf("%v %T\n",diff,diff)

	out := make([]byte, len(name))
	for i,c := range p {
		if c >= 'a' &&  c <= 'z' {
			c  -= diff //convert to captial only if letter 
		}
		out[i] = c
	}
	return out 
}
