#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Oasis
{
		class Doge
{
public:
	Doge( GameDataRef data);
	
	void Draw( );
	
	void update( float dt);
	
	void Tap( );
	
	const sf::Sprite &GetSprite() const;
private:
	GameDataRef _data;
	
	sf::Sprite _dogeSprite;
	
	sf::Clock _movementClock;
	
	int _dogeState;
};
}
