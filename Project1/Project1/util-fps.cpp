#include "util-fps.h"
#include <iostream>

using namespace util;

void Fps::update() {
	if (clock.getElapsedTime().asSeconds() >= 1.f) {
		fps = frames;
		frames = 0;
		clock.restart();
	}
	frames++;
}
