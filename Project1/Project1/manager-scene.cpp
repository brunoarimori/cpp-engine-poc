#include <string>
#include "manager-scene.h"
#include "engine.h"

SceneManager::SceneManager(Engine* e): engine(e) {

}

bool SceneManager::addScene(std::unique_ptr<BaseScene> scene) {
	auto name = scene->getName();
	scene->setup(engine);
	scene->init();
	std::cout << name << " scene added" << std::endl;
	scenes.push_back(std::move(scene)); // emplace_back here?
	return true;
}

bool SceneManager::setScene(const std::string& name) {
	for (auto& s : scenes) {
		if (s->getName() == name) {
			current = s.get();
			return true;
		}
	}
	return false;
}


