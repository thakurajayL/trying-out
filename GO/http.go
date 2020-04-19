package main

import (
	"fmt"
	"net/http"
)

func contentType(url string) (string, error) {
	resp, err := http.Get(url)
	if err != nil {
		return "", err
	}

	defer resp.Body.Close()
	ctype := resp.Header.Get("Content-Type")
	if ctype == "" {
		return "", fmt.Errorf("can't find Content-Type header")
	}
	return ctype, nil
}

func main() {
	ctype, err  := contentType("https://linkedin.com")
	if err != nil {
		fmt.Printf("ERROR : %s\n",err)
	} else {
		fmt.Println(ctype)
	}
}
