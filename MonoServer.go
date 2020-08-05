package main

import (
	"fmt"
	// "github.com/monotrade/monotrade-platform/api"
)

type IMonoServer interface {
	Start()
	Stop()
}

type MonoServer struct{}

func (server *MonoServer) Start() {
	fmt.Println("server start")
	// tick := api.Tick{}
}

func (server *MonoServer) Stop() {
	fmt.Println("server stop")
}
