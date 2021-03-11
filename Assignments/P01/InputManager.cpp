//
//  InputManager.cpp
//  SFML Template
//
//  Created by Derrik Pollock on 3/2/21.
//


#include "InputManager.hpp"

namespace Oasis
{

bool InputManager::IsSpriteClicked(sf:: Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed( button ) )
    {
        sf::IntRect tempCirc(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        
        if (tempCirc.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i GetMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition( window );
}
}
