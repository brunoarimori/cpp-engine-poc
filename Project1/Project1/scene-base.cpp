#include "scene-base.h"
#include "engine.h"

BaseScene::BaseScene(const std::string& n) : name(n) {
	// std::cout << "base scene constructor called" << std::endl;
}

void BaseScene::setup(Engine* e) {
	engine = e;
	// std::cout << "base scene setup called" << std::endl;
}

