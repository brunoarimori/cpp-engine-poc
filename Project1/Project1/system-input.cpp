#include "system-input.h"
#include "event-log.h"
#include "event-input.h"
#include "flags-input.h"
#include "engine.h"
#include "comp-body.h"
#include "comp-controllable.h"
// #include "comp-state.h"


InputSystem::InputSystem() {
	// std::cout << "input system constructor called" << std::endl;
}

void InputSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("input system initialized");
}

void InputSystem::updateControllable(int input) {
	BaseSystem::registry->view<Component::Controllable, Component::Body>().each([&](auto entity, Component::Controllable &controllable, Component::Body &body) {
		controllable.lastInput = controllable.currentInput;
		controllable.currentInput = input;
	});
}

void InputSystem::update() {
	while (BaseSystem::engine->getWindow().pollEvent(event)) {
		BaseSystem::dispatcher->trigger<Event::InputEvent>(event);
		switch (event.type) {
		case sf::Event::Closed:
			BaseSystem::engine->getWindow().close();
			break;
		case sf::Event::KeyPressed:
			// BaseSystem::dispatcher->trigger<Event::InputEvent>(event.key.code, true);
			updateControllable(event.key.code);
			break;
		case sf::Event::KeyReleased:
			// BaseSystem::dispatcher->trigger<Event::InputEvent>(event.key.code, false);
			//input = event.key.code;
			break;
		}
		// std::cout << input << " " << active << std::endl;
	}
}

