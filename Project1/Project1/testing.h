#pragma once

#include "manager-system.h"
#include "pool-components.h"
#include "pool-flags.h"

class Player {
public:
	void playerMaker(entt::registry<>* registry);
};

class Gui {
public:
	void logWindowMaker(entt::registry<>* registry);
};




