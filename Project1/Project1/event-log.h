#pragma once
#include <string>

namespace Event {
	struct LogEvent {
		std::string message;
		LogEvent(std::string message) : message(message) {}
	};
}