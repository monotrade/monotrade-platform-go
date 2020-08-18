package platform

import (
	"fmt"

	"github.com/monotrade/platform/actors"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/monotrade/api"
)

type Platform struct {
	context *actor.RootContext
}

func (p Platform) Start() {
	fmt.Println("starting platform")

	p.context = actor.EmptyRootContext
}

func (p Platform) AddGateway(g api.Gateway) {
	fmt.Println(g)

	props := actor.PropsFromProducer(func() actor.Actor {
		return &actors.GatewayActor{Gateway: g}
	})
	pid := p.context.Spawn(props)
	p.context.Send(pid, "Roger")
	g.Start()
}
