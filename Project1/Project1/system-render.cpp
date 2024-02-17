#include "system-render.h"
#include "flags-directions.h"
#include "comp-body.h"
#include "comp-renderable.h"
#include "comp-movable.h"
#include "event-log.h"
#include "engine.h"

#include <fstream>
#include <nlohmann/json.hpp>

RenderSystem::RenderSystem() {
}

void RenderSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("render system initialized");
	// BaseSystem::dispatcher->sink<Event::LogEvent>().connect(this);

	BaseSystem::engine->getRenderManager().addTexture("player", "assets/sprites/sheet-player.png");
	BaseSystem::engine->getRenderManager().addTexture("grid", "assets/sprites/grid.png");
	BaseSystem::engine->getRenderManager().loadSpriteMap("player", "assets/sprites/sheetmap-mobile.json");
	BaseSystem::engine->getRenderManager().loadSpriteMap("grid", "assets/sprites/sheetmap-grid.json");

	sf::View controllableView;
	controllableView.setSize(192.f, 108.f);
	BaseSystem::engine->getRenderManager().addView(controllableView);

}

void RenderSystem::renderControllable() {

	// player should move in tiles? see step event https://www.youtube.com/watch?v=bwP4Mxb3vJA
	// animations should play once as soon as movement button is pressed, loop if still pressed

	BaseSystem::registry->view<Component::Body, Component::Renderable, Component::Movable>().each([&](auto entity, Component::Body& body, Component::Renderable& renderable, Component::Movable& movable) {
		renderable.lastPosition = renderable.currentPosition;
		renderable.currentPosition = body.currentPosition;
		std::string sprite;
		switch (body.direction) {
		case Flags::Directions::SOUTH:
			if (movable.moving) {
				sprite = "southMove";
			}
			else {
				sprite = "southIdle";
			}
			break;
		case Flags::Directions::NORTH:
			if (movable.moving) {
				sprite = "northMove";
			}
			else {
				sprite = "northIdle";
			}
			break;
		case Flags::Directions::WEST:
			if (movable.moving) {
				sprite = "westMove";
			}
			else {
				sprite = "westIdle";
			}
			break;
		case Flags::Directions::EAST:
			if (movable.moving) {
				sprite = "eastMove";
			}
			else {
				sprite = "eastIdle";
			}
			break;
		}
		// BaseSystem::engine->getRenderManager().getSprite(sprite).setPosition(sf::Vector2f(static_cast<float>(body.currentPosition.x), static_cast<float>(body.currentPosition.y)));

		//alter view center, set view, draw (must be in this order to render correctly)
		BaseSystem::engine->getRenderManager().getCurrentView().setCenter(static_cast<float>(body.currentPosition.x), static_cast<float>(body.currentPosition.y));
		BaseSystem::engine->getWindow().setView(BaseSystem::engine->getRenderManager().getCurrentView());
		BaseSystem::engine->getWindow().draw(BaseSystem::engine->getRenderManager().getSprite(sprite));
	});
}


void RenderSystem::update() {
	BaseSystem::engine->getWindow().draw(BaseSystem::engine->getRenderManager().getSprite("basic"));
	renderControllable();
}
