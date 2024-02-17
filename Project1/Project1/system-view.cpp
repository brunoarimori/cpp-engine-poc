#include "system-view.h"
#include "event-log.h"
#include "engine.h"
#include "comp-renderable.h"
#include "comp-controllable.h"

ViewSystem::ViewSystem() {

}

void ViewSystem::init() {
	playerView.setSize(192.f, 108.f);
}

void ViewSystem::update() {
	BaseSystem::registry->view<Component::Controllable, Component::Renderable>().each([&](auto entity, Component::Controllable& controllable, Component::Renderable& renderable) {
		playerView.setCenter(static_cast<float>(renderable.currentPosition.x), static_cast<float>(renderable.currentPosition.y));
	});
	BaseSystem::engine->getWindow().setView(playerView);
}
