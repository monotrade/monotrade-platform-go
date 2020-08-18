package platform

import (
	"fmt"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/monotrade/api"
	"github.com/monotrade/platform/actors"
)

type Platform struct {
	//context :*actor.RootContext
}

func (p Platform) Start() {
	fmt.Println("starting platform")

	// context = actor.EmptyRootContext
}

func (p Platform) AddGateway(g api.Gateway) {
	fmt.Println(g)

	context := actor.EmptyRootContext
	props := actor.PropsFromProducer(func() actor.Actor { return &actors.GatewayActor{} })
	pid := context.Spawn(props)

	context.Send(pid, "Roger")

	g.Start()
}
