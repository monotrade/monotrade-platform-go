module console-demo

go 1.14

replace github.com/monotrade/api => ../api

replace github.com/monotrade/platform => ../platform

require (
	github.com/AsynkronIT/goconsole v0.0.0-20160504192649-bfa12eebf716
	github.com/monotrade/api v0.0.0
	github.com/monotrade/platform v0.0.0
)
