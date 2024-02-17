#include "testing.h"
#include <iostream>

void Player::playerMaker(entt::registry<>* registry) {
	auto entity = registry->create();
	registry->assign<Component::Body>(entity, sf::Vector2i(10, 0), sf::Vector2i(1, 0), static_cast<int>(Flags::Directions::SOUTH));
	registry->assign<Component::Movable>(entity, Flags::Movement::DEF_VEL, false);
	registry->assign<Component::Controllable>(entity);
	registry->assign<Component::Renderable>(entity, sf::Vector2i(0, 0), "playerSprites");
}

void Gui::logWindowMaker(entt::registry<>* registry) {
	// auto entity = registry->create();
}
