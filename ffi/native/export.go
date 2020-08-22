package main

//this can generate a .h file

import "C"

import "fmt"

//for export, required.

//export InitPlatform
func InitPlatform() {
	fmt.Println("I Love You!")
}

func main() {
	// Need a main function to make CGO compile package as C shared library
}
