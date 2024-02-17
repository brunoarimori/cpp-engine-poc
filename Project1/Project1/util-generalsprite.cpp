#include "util-generalsprite.h"
#include "flags-values.h"

#include <iostream>

using namespace util;

GeneralSprite::GeneralSprite() {
	std::cout << "general sprite constructor called .................." << std::endl;
}

void GeneralSprite::addRect(sf::IntRect intRect) {
	textureRectVector.push_back(intRect);
	if (textureRectVector.size() == 1) {
		setFrame(0, false);
	}
	if (textureRectVector.size() == 2) {
		currentFrame = 0;
		if (frameTime == sf::Time::Zero) {
			frameTime = sf::seconds(Flags::Movement::DEF_ANIM);
		}
	}
}

void GeneralSprite::setFrame(std::size_t frame, bool resetTime) {
	sf::IntRect rect = textureRectVector[frame];

	vertices[0].position = sf::Vector2f(0.f, 0.f);
    vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);

    vertices[0].texCoords = sf::Vector2f(left, top);
    vertices[1].texCoords = sf::Vector2f(left, bottom);
    vertices[2].texCoords = sf::Vector2f(right, bottom);
    vertices[3].texCoords = sf::Vector2f(right, top);

	if (resetTime) currentTime = sf::Time::Zero;
}

void GeneralSprite::update(sf::Time deltaTime) {
	if (textureRectVector.size() > 1) {
		currentTime += deltaTime;
		if (currentTime >= frameTime) {
			currentTime = sf::microseconds(currentTime.asMicroseconds() % frameTime.asMicroseconds());
			if (currentFrame + 1 < textureRectVector.size()) {
				currentFrame++;
			}
			else {
				currentFrame = 0;
			}
			setFrame(currentFrame, false);
		}
	}
}

void GeneralSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (texture) {
        states.transform *= getTransform();
        states.texture = texture;
        target.draw(vertices, 4, sf::Quads, states);
    }
}
