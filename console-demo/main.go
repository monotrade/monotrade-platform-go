package main

import (
	"fmt"

	"github.com/monotrade/api/market"
	"github.com/monotrade/platform"
)

func main() {
	// 创建一个新的结构体
	fmt.Println(market.Tick{Symbol: "hello"})

	var p platform.Platform

	p.Start()
}
