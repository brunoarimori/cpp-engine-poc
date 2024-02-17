#include "system-log.h"
#include "engine.h"

LogSystem::LogSystem() {
	// std::cout << "log system constructor called" << std::endl;
}

void LogSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("log system initialized");
	BaseSystem::dispatcher->sink<Event::LogEvent>().connect(this);
}

void LogSystem::update() {

}

void LogSystem::receive(const Event::LogEvent& log) {
	std::cout << log.message << std::endl;
}