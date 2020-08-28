package main

import (
	. "github.com/monotrade/api/message"
	"github.com/monotrade/platform"
)

func main() {

	var p *platform.Platform = platform.NewPlatform()

	p.AddGateway(new(MockGateway))

	p.Start()

	//vnpy
	// event_engine = EventEngine()
	// main_engine = MainEngine(event_engine)
	// #main_engine.add_gateway(CtpGateway)
	// main_engine.add_gateway(RootnetGateway)

	// main_engine.add_app(CtaExtStrategyApp)
	// main_engine.add_app(ETFMonitorApp)

	// main_engine.add_app(RiskManagerApp)
	// #main_engine.add_app(DataRecorderApp)
	// # 需要rqdatac
	// #main_engine.add_app(ScriptTraderApp)

	// main_window = MainWindow(main_engine, event_engine)
	// main_window.showMaximized()

	//vnpy
	//def add_strategy(self, class_name: str, strategy_name: str, vt_symbol: str, setting: dict)
	//p.AddStrategy(strategy,setting)
}
