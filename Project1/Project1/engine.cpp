#include "engine.h"
#include "system-log.h"

// #include "scene-mainmenu.h"
#include "scene-game.h"

Engine::Engine() : sceneManager(this) {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
	window.setFramerateLimit(UPDATES_PER_SEC);
	window.setKeyRepeatEnabled(false);
	std::cout << "engine constructor called" << std::endl;
}

void Engine::stop() {
}

void Engine::start() {
	
	sf::Clock updateTimer;
	sf::Clock baseTimer;
	sf::Time remainingTime;
	sf::Time deltaTime;

	systemManager.setup(this);
	systemManager.addSystem(std::make_unique<LogSystem>());

	sceneManager.addScene(std::make_unique<GameScene>());
	if (sceneManager.setScene("game")) std::cout << "scene set as game" << std::endl;
	static const sf::Time timestep = sf::milliseconds(static_cast<sf::Int32>(TIMESTEP_S * 1000));

	while (Engine::window.isOpen()) {
		deltaTime = updateTimer.restart();
		remainingTime += deltaTime;
		while (remainingTime > timestep) {
			remainingTime -= timestep;
			// update here
			fps.update();
			window.clear();
			// sceneManager.getScene()->update();
			// update systems -> update sprites -> update views
			systemManager.update();
			renderManager.update();
			window.display();
		}
	}
}
