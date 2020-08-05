package main

// "git.apache.org/thrift.git/lib/go/thrift"

//"github.com/monotrade/monotrade-sdk/monotrade/type"
//"../monotrade-sdk/monotrade/type"
//"../monotrade-sdk/..."

func main() {
	// x := monotrade.monotrade.types.PriceType{}
	// fmt.Printf("hello, world\n")
	// fmt.Printf(x)
	server := new(MonoServer)
	server.Start()
}
