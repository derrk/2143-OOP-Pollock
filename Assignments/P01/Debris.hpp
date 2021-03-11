#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace Oasis
{
	class Debris
	{
	public:
		Debris(GameDataRef data);
		
		void spawnBottomDebris();
		void spawnTopDebris();
		void spawnInvisibleDebris();
		void spawnScoringDebris();
		void MoveDebris( float dt );
		void DrawDebris( );
		void randomizeDebrisOffset( );
		
		const std::vector<sf::Sprite> &GetSprites( ) const;
		std::vector<sf::Sprite> &GetScoringSprites( );
		
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> debrisSprites;
		std::vector<sf::Sprite> scoringDebris;
		
		int _landHeight;
		int _debrisSpawnYOffset;
	
	};

}
