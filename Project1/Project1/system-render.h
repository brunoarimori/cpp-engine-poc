#pragma once

#include <SFML/Graphics.hpp>
#include "system-base.h"
#include "util-generalsprite.h"

class RenderSystem : public BaseSystem {
	void renderControllable();
public:
	RenderSystem();
	void init();
	void update();
};