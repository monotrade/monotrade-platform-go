package main

/*
#cgo CFLAGS: -I./include -I../../vc/include

#cgo LDFLAGS: -L../../vc/lib -L./lib -lKSMMApi

#include "export.h"
*/
import "C"

import "fmt"

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
	// dll32 := syscall.NewLazyDLL("KSMMApi.dll")
	// fmt.Println("call dll:", dll32.Name)
	// //获得函数
	// g := dll32.NewProc("LBM_Plugin.InitPlugin")
	// g.Call()

	ret := C.InitPluginUseCfg() //PST_tagInitInfo pInitInfo
	fmt.Println(ret)
}

func abort(funcname string, err error) {
	panic(funcname + " failed: " + err.Error())
}
