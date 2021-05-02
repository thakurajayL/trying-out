package main

import (
	"fmt"
	"net"
)

func main() {
	fmt.Println("UDP Server")

	//Open socket
	udpAddr, err := net.ResolveUDPAddr("udp", "0.0.0.0:8805")
	if err != nil {
		fmt.Println("Wrong Address")
		return
	}

	fmt.Println("Resolve Success ", udpAddr)
	//Listen for client connection
	udpConn, err := net.ListenUDP("udp", udpAddr)
	if err != nil {
		fmt.Println(err)
		fmt.Println("listen error ", udpAddr)
	}

	for {
		var buf [2048]byte
		fmt.Println("listen for packets")
		n, err := udpConn.Read(buf[0:])
		if err != nil {
			fmt.Println("Error Reading")
		} else {
			fmt.Println("Message : ", string(buf[0:n]))
		}
	}
}
