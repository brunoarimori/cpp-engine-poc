#pragma once

#include "system-base.h"

class GridSystem : public BaseSystem {
private:
public:
	GridSystem();
	void init();
	void update();

	// bool loadGrid(std::string path);
};