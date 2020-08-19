package main

//会生成头文件
import "C"

//for export
//export 的注释是定义的入口描述不能省略

//export InitPlatform
func InitPlatform() {

}

func main() {
	// Need a main function to make CGO compile package as C shared library
}
