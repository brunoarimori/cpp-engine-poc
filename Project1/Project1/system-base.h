#pragma once

#include <SFML/Window/Event.hpp>
#include <entity/registry.hpp>
#include <signal/dispatcher.hpp>

class BaseSystem {
protected:
	class Engine* engine;
	entt::registry<>* registry;
	entt::dispatcher* dispatcher;
	sf::Event event;
public:
	BaseSystem();
	inline virtual ~BaseSystem() {};

	void setup(Engine *e, entt::registry<>* r, entt::dispatcher* d);
	virtual void init() = 0;
	virtual void update() = 0;
	// virtual void stop() = 0;
};

