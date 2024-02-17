#pragma once
#include <string>

class BaseScene {
	std::string name;
protected:
	class Engine* engine;
	class SceneManager* sceneManager;
public:
	BaseScene(const std::string& n);
	inline virtual ~BaseScene() {};

	void setup(Engine* e);
	virtual void init() = 0;
	virtual void update() = 0;
	inline const std::string& getName() { return name; }
};
