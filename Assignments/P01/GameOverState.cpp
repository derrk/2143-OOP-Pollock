#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"


#include <iostream>

namespace Oasis
{
GameOverState::GameOverState(GameDataRef data ) : _data( data )
{
	
}

void GameOverState::Init()
{
	
	std::cout << "Game Over State" << std::endl;
	_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH );
	
	_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
}

void GameOverState::HandleInput()
{
	sf::Event event;
	
	while(_data->window.pollEvent( event ) )
	{
		if ( sf::Event::Closed == event.type )
		{
			_data->window.close();
		}
	}
}

void GameOverState::Update(float dt)
{
	
}

void GameOverState::Draw(float dt)
{
	_data->window.clear( );
	
	// draw background
	_data->window.draw( _background);
	// display background that has been created
	_data->window.display( );
}
}

