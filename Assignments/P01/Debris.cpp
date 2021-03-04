#include <iostream>
#include "Debris.hpp"

namespace Oasis
{
	Debris::Debris( GameDataRef data ) : _data( data )
	{
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_debrisSpawnYOffset = 0;
		
	}

void Debris::spawnBottomDebris()
{
	sf::Sprite sprite(_data->assets.GetTexture( "Debris Up") );
	// spawns debris at the bottom of the screen
	sprite.setPosition( _data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _debrisSpawnYOffset );
	debrisSprites.push_back( sprite );
}
void Debris::spawnTopDebris()
{
	sf::Sprite sprite(_data->assets.GetTexture( "Debris Down") );
	// spawns debris at the top
	sprite.setPosition( _data->window.getSize().x, -_debrisSpawnYOffset);
	debrisSprites.push_back( sprite );
}
void Debris::spawnInvisibleDebris()
{
	sf::Sprite sprite(_data->assets.GetTexture( "Debris Up") );
	// spawns debris at the top
	sprite.setPosition( _data->window.getSize().x, -_debrisSpawnYOffset );
	sprite.setColor(sf::Color(0,0,0,0));
	// store debris in vector
	debrisSprites.push_back( sprite );
}
void Debris::spawnScoringDebris()
{
	sf::Sprite sprite(_data->assets.GetTexture( "Scoring Debris") );
	// spawns debris at the top
	sprite.setPosition( _data->window.getSize().x, 0);
	
	// store debris in vector
	debrisSprites.push_back( sprite );
}

void Debris::MoveDebris( float dt )
{
	for (unsigned short int i = 0; i < debrisSprites.size(); i++)
	{
		// if statement to delete debris once it is off screen
		if (debrisSprites.at( i ).getPosition().x < 0 - debrisSprites.at(i).getGlobalBounds().width )
		{	// clear the debris so memory is not getting full
			debrisSprites.erase( debrisSprites.begin() + i);
		}
		else	// move the debris as normal
		{
		// sets the debris movement to be indepedent of framerate
		float movement = DEBRIS_MOVEMENT_SPEED * dt;
		
		debrisSprites.at( i ).move( -movement , 0);		// is moved to the left across the screen
		}
	}
	std::cout << debrisSprites.size() << std::endl;
	
	for (unsigned int i = 0; i < debrisSprites.size(); i++)
	{
		// if statement to delete debris once it is off screen
		if (scoringDebris.at( i ).getPosition().x < 0 - scoringDebris.at(i).getGlobalBounds().width )
		{	// clear the debris so memory is not getting full
			scoringDebris.erase( debrisSprites.begin() + i);
		}
		else	// move the debris as normal
		{
		// sets the debris movement to be indepedent of framerate
		float movement = DEBRIS_MOVEMENT_SPEED * dt;
		
			scoringDebris.at( i ).move( -movement , 0);		// is moved to the left across the screen
		}
	}
	std::cout << debrisSprites.size() << std::endl;
}

	void Debris::DrawDebris()
{
	for (unsigned int i = 0; i < debrisSprites.size(); i++)
	{
		_data->window.draw( debrisSprites.at(i) );
	}
}
void Debris::randomizeDebrisOffset()
{
	_debrisSpawnYOffset = rand() % ( _landHeight + 1);
}
const std::vector<sf::Sprite> &Debris::GetSprites( ) const
	{
		return debrisSprites;
	}
	std::vector<sf::Sprite> &Debris::GetScoringSprites( )
	{
		return scoringDebris;
	}
}
