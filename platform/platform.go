package platform

import (
	"fmt"
)

type Platform struct {
}

func (p Platform) Start() {
	fmt.Println("starting platform")
}
