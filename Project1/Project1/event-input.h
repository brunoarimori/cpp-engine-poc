#pragma once
#include <SFML/Window/Event.hpp>

namespace Event {
	struct InputEvent {
		sf::Event input;
		InputEvent(sf::Event input) : input(input) {}
	};
}
