#include "system-move.h"
#include "event-log.h"
#include "flags-directions.h"
#include "flags-values.h"
#include "comp-body.h"
#include "comp-controllable.h"
#include "comp-movable.h"
#include "engine.h"

MoveSystem::MoveSystem() {
	// std::cout << "move system constructor called" << std::endl;
}

void MoveSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("move system initialized");
}

void MoveSystem::update() {
	BaseSystem::registry->view<Component::Body, Component::Movable>().each([&](auto entity, Component::Body& body, Component::Movable& movable) {
		// if (movable.moving) {
		// 	switch (body.direction) {
		// 	case Flags::Directions::EAST:
		// 		if (body.lastPosition.x == body.currentPosition.x) {
		// 		}
		// 		if (body.currentPosition.x >= body.lastPosition.x - 16) {
		// 			body.currentPosition.x -= Flags::Movement::DEF_VEL;
		// 		}
		// 		break;
		// 	case Flags::Directions::NORTH:
		// 		body.currentPosition.y -= Flags::Movement::DEF_VEL;
		// 		break;
		// 	case Flags::Directions::SOUTH:
		// 		body.currentPosition.y += Flags::Movement::DEF_VEL;
		// 		break;
		// 	case Flags::Directions::WEST:
		// 		body.currentPosition.x += Flags::Movement::DEF_VEL;
		// 		break;
		// 	}
		// }

		switch (body.direction) {
		case Flags::Directions::EAST:
			break;
		case Flags::Directions::NORTH:
			break;
		case Flags::Directions::SOUTH:
			break;
		case Flags::Directions::WEST:
			break;
		}
	});
}

void MoveSystem::receive(const Event::InputEvent& input) {
	// std::cout << log.message << std::endl;
}
