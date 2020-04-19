package main

import (
	"fmt"
	"os"
	"log"
	"github.com/pkg/errors"
)
type Config struct {
	num int
	// we can add many more config fields 
}

func readConfig (path string) (*Config, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, errors.Wrap(err,"Can't open configuration file")
	}

	defer file.Close()

	cfg := &Config{1}
	//parse the file and update Config
	return cfg, nil
}

func setupLogging() {
	out, err := os.OpenFile("app.log",os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return
	}
	log.SetOutput(out) // logs will be sent to file nmow instead of stdout 
}

func main() {
	fmt.Println("Welcome.")
	setupLogging()
	cfg, err := readConfig("/unknownpath/config.yaml")
	if err != nil {
		fmt.Fprintf(os.Stderr, "error: %s\n",err)
		log.Printf("error : %+v",err)
		os.Exit(1)
	}
	fmt.Println(cfg)
}
