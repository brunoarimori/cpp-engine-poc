#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace util {
	class Fps {
	private:
		unsigned int frames;
		unsigned int fps;
		sf::Clock clock;
	public:
		Fps() : frames(0), fps(0) {}
		const unsigned int getFps() { return fps; };
		void update();
	};
}
