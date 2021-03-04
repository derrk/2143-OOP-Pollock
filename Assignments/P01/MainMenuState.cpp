
#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Oasis
{
	MainMenuState::MainMenuState(GameDataRef data ) : _data( data )
{
	
}

void MainMenuState::Init()
{
	_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	
	_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH );

	_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH );

	
	_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
	
	_title.setTexture(this->_data->assets.GetTexture("Game Title"));
	
	_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
	
	// set position of the title to be centered on the screen
	_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2 ), _title.getGlobalBounds().height/2 );
	// set position of the play button to be centered on the screen
	_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2 ), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2 ));
	
}

void MainMenuState::HandleInput()
{
	sf::Event event;
	
	while(_data->window.pollEvent( event ) )
	{
		if ( sf::Event::Closed == event.type )
		{
			_data->window.close();
		}
		if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState( StateRef(new GameState(_data)), true);		}
		
	}
}

void MainMenuState::Update(float dt)
{
	
}

void MainMenuState::Draw(float dt)
{
	_data->window.clear( );
	
	// draw background
	_data->window.draw( _background);
	// draw the game title
	_data->window.draw( _title);
	// draw the play button
	_data->window.draw( _playButton);
	
	// display background that has been created
	_data->window.display( );
}
}

