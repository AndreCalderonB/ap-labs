package main

import (
	"fmt"
	"net"
	"os"
	"strings")

type localClock struct {
	location   string
	connection net.Conn
}

func (c localClock) handleConn() {

	//for  {
	time := make([]byte, len("15:04:05\n"))
	_, err := c.connection.Read(time)
	if err != nil {
		fmt.Printf("%s\n", err)
	} else {
		fmt.Printf("Local time in %s: %s\n", c.location, time)
	}
	c.connection.Close()
}

func main() {
	if len(os.Args) < 2 {
		fmt.Printf("Please, set the port server you want to connect. Aborted.\n")
		return
	}

	for _, server := range os.Args[1:] {
		var data = strings.Split(server, "=")
		if len(data) != 2 {
			fmt.Printf("Insert the input properly. Aborted.\n")
			return
		}
		conn, err := net.Dial("tcp", data[1])
		if err != nil {
			fmt.Printf("Error in connection. Aborted.\n")
			return
		}
		myClock := localClock{
			location:   data[0],
			connection: conn,
		}
		myClock.handleConn()

	}

}