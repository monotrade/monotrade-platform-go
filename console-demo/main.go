package main

import (
	"fmt"

	"github.com/monotrade/api"
	"github.com/monotrade/platform"
)

func main() {
	// 创建一个新的结构体
	fmt.Println(api.Tick{Symbol: "hello"})

	var p *platform.Platform = platform.NewPlatform()

	p.AddGateway(new(MockGateway))
	p.Start()
}
