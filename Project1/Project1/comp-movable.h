#pragma once
#include <SFML/System/Vector2.hpp>

namespace Component {
	struct Movable {
		// used to move entity on system-move, velocity is the amount of pixels to be moved every tick
		Movable(int velocity, bool moving) 
			: velocity(velocity), moving(moving) {};
		int velocity;
		bool moving;
	};
}