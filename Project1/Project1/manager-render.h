#pragma once

#include <SFML/Graphics.hpp>
#include "system-base.h"
#include "util-generalsprite.h"

class RenderManager {
private:
	// textures, sprites and animations
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, util::GeneralSprite> sprites;
	sf::Clock animClock;

	// views
	std::vector<sf::View> views;

public:
	RenderManager();

	// add id and texture to textures map
	bool addTexture(std::string textureId, std::string texturePath);
	// add sprite to sprites map
	bool addSprite(std::string spriteId, const util::GeneralSprite& sprite);
	// add view to views vector
	bool addView(const sf::View& view);

	inline sf::Texture& getTexture(std::string id) { return textures[id]; };
	inline util::GeneralSprite& getSprite(std::string id) { return sprites[id]; };
	inline sf::View& getCurrentView() { return views.front(); };
	
	// read sprite json and texture, add it to sprites stack
	bool loadSpriteMap(std::string textureId, std::string spriteMapPath);

	void update();
};
