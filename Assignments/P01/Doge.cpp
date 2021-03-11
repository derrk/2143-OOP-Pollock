#include "Doge.hpp"

namespace Oasis
{
	Doge::Doge(GameDataRef data ) : _data( data )
{
	_dogeSprite.setTexture( _data->assets.GetTexture("Doge Frame 1"));
	
	_dogeSprite.setPosition(( _data->window.getSize().x / 4 ) -( _dogeSprite.getGlobalBounds().width / 2)  , ( _data->window.getSize().y / 2 ) -( _dogeSprite.getGlobalBounds().height / 2));
	_dogeState = DOGE_STATE_STILL;
}
void Doge::Draw()
{
	_data->window.draw(_dogeSprite );
}
void Doge::update(float dt)
{
	if (DOGE_STATE_FALLING == _dogeState)
	{
		_dogeSprite.move( 0, GRAVITY * dt);
	}
	else if ( DOGE_STATE_FLYING == _dogeState)
	{
		_dogeSprite.move(0 , -FLYING_SPEED * dt);
	}
	if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION )
	{
		_movementClock.restart();
		_dogeState = DOGE_STATE_FALLING;
	}
}
	void Doge::Tap()
	{
		_movementClock.restart();
		_dogeState = DOGE_STATE_FLYING;
	}
const sf::Sprite &Doge::GetSprite() const
{
	return _dogeSprite;
}
}

