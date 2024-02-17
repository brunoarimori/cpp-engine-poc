#pragma once
#include <SFML/System/Vector2.hpp>

namespace Component {
	struct Renderable {
		// used to render entity based on comp-body position
		Renderable(const sf::Vector2i& position, std::string spriteId) 
			: lastPosition(position), currentPosition(position), spriteId(spriteId) {};
		sf::Vector2i lastPosition, currentPosition;
		std::string spriteId;
	};
}
