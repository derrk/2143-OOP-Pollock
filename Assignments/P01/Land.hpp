#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Oasis
{
	class Land
{
public:
	Land(GameDataRef data);
	
	void moveLand( float dt);
	void drawLand( );
	
	const std::vector<sf::Sprite> &GetSprites() const;
	
private:
	GameDataRef _data;
	
	std::vector<sf::Sprite>_landSprites;
	
};
}

