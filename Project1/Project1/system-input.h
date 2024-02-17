#pragma once

#include "system-base.h"

class InputSystem : public BaseSystem {
private:
	void updateControllable(int input);
public:
	InputSystem();
	void init();
	void update();
};
