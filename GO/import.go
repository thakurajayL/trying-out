package main

import (
	"fmt"
	"log"
	"os"
	"github.com/pelletier/go-toml"
)

type Config struct {
	Login struct {
		User string
		Password string
	}
}

func main() {
	file, err := os.Open("sample.toml")
	if err != nil {
		log.Fatalf("error: can't open config file - %s",err)
	}
	defer file.Close()

	cfg := &Config{}
	dec := toml.NewDecoder(file)
	if err:= dec.Decode(cfg); err != nil  {
		log.Fatalf("error: can't decode configuration file = %s\n",err)
	}
	fmt.Printf("%+v\n",cfg)
}
