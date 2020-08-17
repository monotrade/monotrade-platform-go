package api

//Context  策略上下文
type Context struct {
	title string
}

//IStrategy 策略接口
type IStrategy interface {
	OnTick(ctx Context, tick Tick)
}
