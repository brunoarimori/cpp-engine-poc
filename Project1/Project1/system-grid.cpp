#include "system-grid.h"
#include "event-log.h"
#include "engine.h"
#include "comp-tile.h"

GridSystem::GridSystem() {

}

void GridSystem::init() {
	BaseSystem::dispatcher->trigger<Event::LogEvent>("grid system initialized");
	// load tileset, load region file with each tile info
}

void GridSystem::update() {

}
