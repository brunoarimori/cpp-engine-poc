#pragma once

#include <entity/registry.hpp>
#include <signal/dispatcher.hpp>

#include "system-base.h"


class SystemManager {
	class Engine* engine;
	entt::registry<> registry;
	entt::dispatcher dispatcher;
	std::vector<std::unique_ptr<BaseSystem>> systems;
public:
	SystemManager();
	void setup(Engine* e);
	void update();

	bool addSystem(std::unique_ptr<BaseSystem> system);
	inline entt::registry<>& getRegistry() { return registry; };
};