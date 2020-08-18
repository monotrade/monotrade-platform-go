package main

/*

#cgo CFLAGS: -Iinclude

#cgo LDFLAGS: -Llib -llibvideo

#include "LBM_Plugin.h"

*/
import (
	"C"
	"fmt"
	"syscall"
)

func main() {
	fmt.Println("hello")
	//立即加载DLL
	// h, err := syscall.LoadLibrary("KSMMApi.dll")
	// if err != nil {
	// 	abort("LoadLibrary", err)
	// }

	// defer syscall.FreeLibrary(h)
	// proc, err := syscall.GetProcAddress(h, "GetVersion")
	// if err != nil {
	// 	abort("GetProcAddress", err)
	// }
	// C.ST_THREADPOOL.InitPlugin()

	//懒加载
	dll32 := syscall.NewLazyDLL("KSMMApi.dll")
	fmt.Println("call dll:", dll32.Name)
	//获得函数
	g := dll32.NewProc("LBM_Plugin.InitPlugin")
	g.Call()
}

func abort(funcname string, err error) {
	panic(funcname + " failed: " + err.Error())
}
