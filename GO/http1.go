package main
import (
	"fmt"
	"log"
	"os"
	"io"
	"bytes"
	"encoding/json"
	"net/http"
)

type Job struct {
	User string `json:"User"`
	Action  string `json:"Action"`
	Count int `json:"Count"`
}

func main() {
	fmt.Println("Welcome \n")
	resp, err := http.Get("https://httpbin.org/get")
	if err != nil {
		log.Fatalf("can't call httpbin.org")
	}
	defer resp.Body.Close()
	io.Copy(os.Stdout, resp.Body)
	fmt.Println(".........");
	job := &Job {
		User: "Ajay",
		Action: "punch",
		Count: 1,
	}
	var buf bytes.Buffer
	enc := json.NewEncoder(&buf)
	if err := enc.Encode(job); err != nil {
		log.Fatalf("error: cant encode job - %s",err)
	}

	resp, err = http.Post("https://httpbin.org/post", "application/json", &buf)
	if err != nil {
		log.Fatalf("error: can't call httpbin.org ")
	}
	defer resp.Body.Close()
	io.Copy(os.Stdout, resp.Body)
}
