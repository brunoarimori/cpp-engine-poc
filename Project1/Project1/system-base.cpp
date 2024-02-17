#include "system-base.h"
#include "engine.h"

BaseSystem::BaseSystem() {
	// std::cout << "base system constructor called" << std::endl;
}

void BaseSystem::setup(Engine *e, entt::registry<>* r, entt::dispatcher* d) {
	registry = r;
	dispatcher = d;
	engine = e;
	// std::cout << "base system setup called" << std::endl;
}