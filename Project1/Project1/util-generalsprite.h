#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace util {
	class GeneralSprite : public sf::Drawable, public sf::Transformable {
	private:
		const sf::Texture* texture;
		std::vector<sf::IntRect> textureRectVector;
		sf::Vertex vertices[4];
		sf::Time frameTime;
		sf::Time currentTime;
		std::size_t currentFrame; // better to use int here?
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		GeneralSprite();
		void addRect(sf::IntRect intRect);
		inline void setTexture(const sf::Texture& t) { texture = &t; };
		inline void setFrameTime(sf::Time time) { frameTime = time; };
		void setFrame(std::size_t frame, bool resetTime);
		void update(sf::Time deltaTime);
	};
}
