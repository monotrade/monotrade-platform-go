package main

import (
	"fmt"

	"github.com/monotrade/monotrade-platform/api"
)

type TradeServer struct{}

func (server *TradeServer) Start() {
	fmt.Println("server start")
	tick := api.Tick{}
}
