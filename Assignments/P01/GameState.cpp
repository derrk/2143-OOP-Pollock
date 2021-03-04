#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "Debris.hpp"
#include "Doge.hpp"

#include <iostream>

namespace Oasis
{
	GameState::GameState(GameDataRef data ) : _data( data )
{
	
}

void GameState::Init()
{
	
std::cout << "Game State" << std::endl;
	
	_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH );
	_data->assets.LoadTexture("Debris Up", DEBRIS_UP_FILEPATH );
	_data->assets.LoadTexture("Debris Down", DEBRIS_DOWN_FILEPATH );
	_data->assets.LoadTexture("Land", LAND_FILEPATH );
	_data->assets.LoadTexture("Doge Frame 1", DOGE_FRAME_1_FILEPATH );
	_data->assets.LoadTexture("Scoring Debris", SCORING_DEBRIS_FILEPATH );
	
// create a new instance of Debris
	debris = new Debris( _data );
	land = new Land( _data);
	doge = new Doge( _data);
	
	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	
	_score = 0;
	
	_gameState = GameStates::eReady;
}

void GameState::HandleInput()
{
	sf::Event event;
	
	while(_data->window.pollEvent( event ) )
	{
		if ( sf::Event::Closed == event.type )
		{
			_data->window.close();
		}
		if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
		{
			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
			doge->Tap( );
			}
		}
	}
}

void GameState::Update(float dt)
{
	if (GameStates::eGameOver != _gameState)
	{
	debris->MoveDebris( dt );
	land->moveLand(dt);
	}
	if (GameStates::ePlaying == _gameState)
	{
		debris->MoveDebris( dt );
	if ( clock.getElapsedTime().asSeconds() > DEBRIS_SPAWN_FREQUENCY )
	{
		debris->randomizeDebrisOffset();
		
		debris->spawnInvisibleDebris();
		debris->spawnBottomDebris();
		debris->spawnTopDebris();
		debris->spawnInvisibleDebris();
		
		clock.restart();
	}
	doge ->update(dt);
		
		std::vector<sf::Sprite> landSprites = land->GetSprites();
		for (int i = 0; i < landSprites.size(); i++)
		{
		if ( collision.CheckSpriteCollision(doge->GetSprite(),landSprites.at(i)))
		{
			_gameState = GameStates::eGameOver;
		}
		}
		
		std::vector<sf::Sprite> debrisSprites = debris->GetSprites();
		for (int i = 0; i < debrisSprites.size(); i++)
		{
		if ( collision.CheckSpriteCollision(doge->GetSprite(), 0.7f ,debrisSprites.at(i), 1.0f))
		{
			_gameState = GameStates::eGameOver;
		}
		}
		std::vector<sf::Sprite> &scoringSprites = debris->GetScoringSprites();
		for (int i = 0; i < scoringSprites.size(); i++)
		{
		if ( collision.CheckSpriteCollision(doge->GetSprite(), 0.7f ,scoringSprites.at(i), 1.0f))
		{
			_score++;
			std::cout << _score << std::endl;
			scoringSprites.erase( scoringSprites.begin()+ i);
		}
		}
	}
}
// This Function generates the background, window, and the debris
void GameState::Draw(float dt)
{
	_data->window.clear( );
	
	// draw background
	_data->window.draw( _background);
	debris->DrawDebris( );
	land->drawLand();
	doge->Draw();
	// display background that has been created
	_data->window.display( );
}
}
