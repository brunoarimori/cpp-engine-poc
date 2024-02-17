#include "scene-game.h"
#include "event-log.h"
#include "engine.h"

#include "system-input.h"
#include "system-move.h"
#include "system-steer.h"
#include "system-render.h"
#include "system-view.h"

// testing
#include "testing.h"

GameScene::GameScene() : BaseScene("game") {
	// std::cout << "game scene constructor called" << std::endl;
}

void GameScene::init() {
	BaseScene::engine->getSystemManager().addSystem(std::make_unique<InputSystem>());
	BaseScene::engine->getSystemManager().addSystem(std::make_unique<SteerSystem>());
	BaseScene::engine->getSystemManager().addSystem(std::make_unique<MoveSystem>());
	BaseScene::engine->getSystemManager().addSystem(std::make_unique<RenderSystem>());
	// BaseScene::engine->getSystemManager().addSystem(std::make_unique<ViewSystem>());
	// std::cout << "game scene initialized" << std::endl;
	Player test;
	test.playerMaker(&BaseScene::engine->getSystemManager().getRegistry());
}

void GameScene::update() {
}
