#include "system-steer.h"
#include "event-log.h"
#include "flags-input.h"
#include "flags-directions.h"
#include "engine.h"
#include "comp-body.h"
#include "comp-movable.h"
#include "comp-controllable.h"
#include "comp-renderable.h"
// #include "comp-state.h"


SteerSystem::SteerSystem() {
}

void SteerSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("steer system initialized");
}

void SteerSystem::update() {
	BaseSystem::registry->view<Component::Controllable, Component::Body, Component::Movable, Component::Renderable>().each([&](auto entity, Component::Controllable &controllable, Component::Body &body, Component::Movable &movable, Component::Renderable &renderable) {
		switch (controllable.currentInput) {
		case Flags::Inputs::UP:
			body.direction = Flags::Directions::NORTH;
			break;
		case Flags::Inputs::DOWN:
			body.direction = Flags::Directions::SOUTH;
			break;
		case Flags::Inputs::LEFT:
			body.direction = Flags::Directions::EAST;
			break;
		case Flags::Inputs::RIGHT:
			body.direction = Flags::Directions::WEST;
			break;
		}
		movable.moving = true;
	});
}