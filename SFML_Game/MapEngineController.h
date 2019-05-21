#pragma once
#include "SFML/Graphics.hpp"
class MapEngineController : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	bool load(sf::Texture tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};

