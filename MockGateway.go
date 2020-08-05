package main

import "fmt"
import "communication"

// "github.com/monotrade/monotrade-platform/api"

type IGateway interface {
	Start()
	Stop()
}

type MockGateway struct{
	tickPub := pubsub.NewPublisher(100*time.Millisecond, 10)
}

func (gateway *MockGateway) Start() {
	fmt.Println("server start")

	defer tickPub.Close()

	//TODO: send tick with routine

}
