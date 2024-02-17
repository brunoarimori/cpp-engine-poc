#pragma once

#include "system-base.h"
#include "event-log.h"

class LogSystem : public BaseSystem {
private:
public:
	LogSystem();
	void init();
	void update();

	void receive(const Event::LogEvent& log);
};