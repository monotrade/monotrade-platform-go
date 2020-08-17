package main

import (
	"fmt"

	"github.com/monotrade/api"
)

func main() {
	// 创建一个新的结构体
	fmt.Println(api.Tick{Symbol: "hello"})
}
