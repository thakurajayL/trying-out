package main

import (
	"fmt"
	"log"
	"net/http"
)

func helloHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w,"Hello ")
}
//curl localhost:8080/hello <--to get the content  
func main() {
	http.HandleFunc("/hello",helloHandler)
	if err := http.ListenAndServe(":8080",nil); err != nil {
		log.Fatal(err)
	}
}
