package main

import (
	"fmt"
<<<<<<< HEAD
	"time"
)

func connect(in chan int, out chan int) {
	for {
		out <- (1 + <-in)
	}
}

func main() {
	message1 := make(chan int)
	message2 := make(chan int)
	total := 0

	go connect(message1, message2)
	go connect(message2, message1)

	for i := 0; i < 1; i++ {
		message1 <- 0
		time.Sleep(time.Duration(1) * time.Second)
		x := <-message1
		total += x
	}

	fmt.Println("Communications Per Second : ", total)
=======
)

func main() {
	var commsPerSecond int

	fmt.Println("Communications Per Second : ", commsPerSecond)
>>>>>>> 4d26fcdcd611edfa7cbeb7b4ac42340829a76999
}
