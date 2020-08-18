package platform

import (
	"fmt"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/monotrade/api"
	"github.com/monotrade/platform/actors"
)

//Go语言中没有构造函数，对象的创建一般交给一个全局的创建函数来完成
func NewPlatform() *Platform {
	return &Platform{actor.EmptyRootContext}
}

type Platform struct {
	context *actor.RootContext
}

func (p Platform) Start() {
	fmt.Println("starting platform")

}

func (p Platform) AddGateway(g api.Gateway) {
	fmt.Println(g)

	// context := actor.EmptyRootContext
	props := actor.PropsFromProducer(func() actor.Actor { return &actors.GatewayActor{} })
	pid := p.context.Spawn(props)

	p.context.Send(pid, "Roger")

	g.Start()
}
