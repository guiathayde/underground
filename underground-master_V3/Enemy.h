#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Character.h"

class Enemy: public Character
{
private:
  
public:
  Enemy(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin, float switchTime, float speed,float jumpHeight);
  ~Enemy();
};