package main

import (
	"fmt"
	"net/http"
)

func returnType(url string, out chan string) {
	resp, err := http.Get(url)
	if err != nil {
		out <- fmt.Sprintf("error %s\n",err)
		return
	}
	defer resp.Body.Close()
	ctype := resp.Header.Get("content-type")
	out <- fmt.Sprintf("%s -> %s \n", url, ctype)
}

func main() {
	urls := []string{
		"https://golang.org",
		"https://api.github.com",
		"https://httpbin.org/xml",
	}
	ch := make(chan string)
	for _,url := range urls {
		go returnType(url, ch)
	}
	for range urls {
		out:= <-ch
		fmt.Println(out)
	}
}
