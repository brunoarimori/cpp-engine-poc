#include "manager-system.h"
#include "engine.h"

SystemManager::SystemManager() {
	std::cout << "system manager constructor called" << std::endl;
}

void SystemManager::setup(Engine* e) {
	engine = e;
	std::cout << "system manager setup called" << std::endl;
}

void SystemManager::update() {
	for (auto& s : systems) {
		s->update();
	}
}

bool SystemManager::addSystem(std::unique_ptr<BaseSystem> system) {
	system->setup(engine, &registry, &dispatcher);
	system->init();
	systems.push_back(std::move(system));
	return true;
}