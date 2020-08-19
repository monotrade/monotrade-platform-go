package api

type Gateway interface {
	Broker
	Feeder
}

type Broker interface {
	Start()
}

type Feeder interface {
	Start()
}
