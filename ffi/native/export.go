package main

//this can generate a .h file

import "C"

//for export, required.

//export InitPlatform
func InitPlatform() {

}

func main() {
	// Need a main function to make CGO compile package as C shared library
}
