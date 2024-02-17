#pragma once

#include "system-base.h"
#include "event-input.h"


class MoveSystem : public BaseSystem {
private:
public:
	MoveSystem();
	void init();
	void update();

	void receive(const Event::InputEvent& input);
	// void step();
};