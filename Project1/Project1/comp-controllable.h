#pragma once

namespace Component {
	struct Controllable {
		// entities with this component can be controlled by player input
		Controllable() {};
		int currentInput;
		int lastInput;
		// id current; should use some id system so only one entity can be controlled at a time
	};
}