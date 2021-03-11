#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Debris.hpp"
#include "Land.hpp"
#include "Doge.hpp"
#include "Collision.hpp"

namespace Oasis
{
	class GameState : public State
{
public:
	GameState(GameDataRef data);
	
	void Init();
	
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	
	private :
	GameDataRef _data;
	
	
	sf::Sprite _background;
	
	Debris *debris;
	Land *land;
	Doge *doge;
	Collision collision;
	
	sf:: Clock clock;
	
	int _gameState;
	
	int _score;
};
	
}
