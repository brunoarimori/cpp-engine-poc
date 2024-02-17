#pragma once
#include <SFML/Window/Event.hpp>

#include "scene-base.h"

class GameScene : public BaseScene {
public:
	GameScene();
	
	void init();
	void update();
};