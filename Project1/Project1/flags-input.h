#pragma once
#include "SFML/Window/Keyboard.hpp"

namespace Flags {
	enum Inputs {
		UP = sf::Keyboard::W,
		DOWN = sf::Keyboard::S,
		LEFT = sf::Keyboard::A,
		RIGHT = sf::Keyboard::D,
		ACTION = sf::Keyboard::E
	};
}
