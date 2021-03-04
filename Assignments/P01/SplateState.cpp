

#include <sstream>
#include "SplateState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Oasis
{
	SplashState::SplashState(GameDataRef data ) : _data( data )
{
	
}

void SplashState::Init()
{
	_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH );
	
	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
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

void SplashState::Update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		_data->machine.AddState( StateRef(new MainMenuState(_data)), true);
	
	}
}

void SplashState::Draw(float dt)
{
	_data->window.clear( );
	
	// draw background
	_data->window.draw( _background);
	// display background that has been created
	_data->window.display( );
}
}
