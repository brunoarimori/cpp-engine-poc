#pragma once
#include <SFML/System/Vector2.hpp>

namespace Component {
	struct Body {
		// holds position, direction and dimensions of entity
		Body(const sf::Vector2i& position, const sf::Vector2i& dimensions, int direction)
			: lastPosition(position), currentPosition(position), dimensions(dimensions), direction(direction) {};
		sf::Vector2i lastPosition, currentPosition, dimensions;
		int direction;
	};
}