package actors

import (
	"fmt"

	"github.com/AsynkronIT/protoactor-go/actor"
)

type GatewayActor struct {
	// Gateway api.Gateway
}

func (state *GatewayActor) Receive(context actor.Context) {
	switch msg := context.Message().(type) {
	case string:
		fmt.Printf("Hello %v\n", msg)

	}
}
