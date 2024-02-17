#include <fstream>
#include <nlohmann/json.hpp>
#include "manager-render.h"

// testing
#include <iostream>

RenderManager::RenderManager() {
	std::cout << "sprite manager constructor called" << std::endl;
}

bool RenderManager::addTexture(std::string textureId, std::string texturePath) {
	sf::Image image;
	sf::Texture texture;
	if (!image.loadFromFile(texturePath)) {
		return false;
	}
	image.createMaskFromColor(sf::Color(255, 0, 255, 255));
	texture.loadFromImage(image);
	textures.insert(std::pair<std::string, sf::Texture>(textureId, texture));
	return true;
}

bool RenderManager::addSprite(std::string spriteId, const util::GeneralSprite& sprite) {
	sprites.insert(std::pair<std::string, util::GeneralSprite>(spriteId, sprite));
	return true;
}

bool RenderManager::addView(const sf::View& view) {
	views.push_back(view);
	return true;
}

bool RenderManager::loadSpriteMap(std::string textureId, std::string spriteMapPath) {
	std::ifstream input(spriteMapPath);
	if (!input.is_open()) {
		return false;
	}
	nlohmann::json json;
	input >> json;
	std::cout << json["sprites"].size() << std::endl;
	for (auto playerSprites : json["sprites"]) {
		// create new sprite
		util::GeneralSprite newSprite;
		newSprite.setTexture(getTexture(textureId));
		// add rects
		for (auto rect : playerSprites["rect"]) {
			sf::IntRect intrect(rect[0], rect[1], rect[2], rect[3]);
			newSprite.addRect(intrect);
		}
		// push sprite into map
		addSprite(playerSprites["id"], newSprite);
	}
	return true;
}

void RenderManager::update() {
	sf::Time tickTime;
	tickTime = animClock.restart();
	for (auto &animatedSprite : sprites) {
		animatedSprite.second.update(tickTime);
	}
}
