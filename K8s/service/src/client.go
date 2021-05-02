package main

import (
	"fmt"
	"net"
    "time"
)

func main() {
	fmt.Println("UDP Client")

    time.Sleep(60*time.Second)
	//Open socket
	udpAddr, err := net.ResolveUDPAddr("udp", "myapp-udp-server")
	if err != nil {
		fmt.Println("Wrong Address")
		return
	}

	fmt.Println("1 Resolve Server Success ", udpAddr.String())

/*
    udpConn, _ := net.Dial("udp", udpAddr+":8805")

    if _, err := udpConn.Write([]byte("hello")); err != nil {
        fmt.Println("Unable to transmit association setup request ", err)
    }
*/

	for {
        time.Sleep(1000*time.Second)
	}
}
