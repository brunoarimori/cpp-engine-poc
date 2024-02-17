#pragma once

#include "system-base.h"
#include <SFML/Graphics/View.hpp>

class ViewSystem : public BaseSystem {
private:
	sf::View playerView;
public:
	ViewSystem();
	void init();
	void update();
};
