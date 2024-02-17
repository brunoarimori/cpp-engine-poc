#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Sleep.hpp>
#include "manager-scene.h"
#include "manager-system.h"
#include "manager-render.h"
#include "util-fps.h"

// testing
#include <iostream>

#define UPDATES_PER_SEC 60
#define TIMESTEP_S 1.f / UPDATES_PER_SEC
#define WINDOW_HEIGHT 560
#define WINDOW_WIDTH 960
#define WINDOW_NAME "Project 1"

class Engine {
	sf::RenderWindow window;
	SceneManager sceneManager;
	SystemManager systemManager;
	RenderManager renderManager;
	util::Fps fps;
public:
	Engine();

	void start();
	void stop();

	inline sf::RenderWindow& getWindow() { return window; }
	inline SceneManager& getSceneManager() { return sceneManager; }
	inline SystemManager& getSystemManager() { return systemManager; }
	inline RenderManager& getRenderManager() { return renderManager; }
};
