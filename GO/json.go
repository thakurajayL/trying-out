package main

import (
	"fmt"
	"log"
	"bytes"
	"os"
	"encoding/json"
)

var data = `
{
	"user": "Ajay T",
	"type" : "deposit",
	"amount" : 1000.4
}
`
// request is bank transactions

type Request struct {
	Login string `json:"user"`
	Type string `json:"type"`
	Amount float64 `json: "amount"`
}

func main() {
	rdr := bytes.NewBufferString(data)
	dec  := json.NewDecoder(rdr)
	req := &Request{}
	if err := dec.Decode(req); err != nil {
		log.Fatalf("error: can't decode - %s\n",err)
	}
	fmt.Printf("Req - %+v \n",req)

	prevBalance := 1300.1
	resp := map[string]interface{} {
		"ok": true,
		"balance": prevBalance+ req.Amount,
	}

	enc := json.NewEncoder(os.Stdout)
	if err := enc.Encode(resp);err != nil {
		log.Fatalf("error can't encode - %s",err)
	}
}
