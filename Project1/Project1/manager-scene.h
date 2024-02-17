#pragma once
#include <vector>
#include <memory>
#include <string>
#include "scene-base.h"

class SceneManager {
	std::vector<std::unique_ptr<BaseScene>> scenes;
	BaseScene* current = nullptr;
	class Engine* engine; //incomplete type
public:
	SceneManager(Engine* e);
	bool addScene(std::unique_ptr<BaseScene> scene);
	bool setScene(const std::string& name);

	inline BaseScene* getScene() { return current; }
};
