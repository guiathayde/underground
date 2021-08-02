#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Character.h"
#include <list>


class Player: public Character
{
private:
  bool isPlayerOne;

public:
  Player(sf::Texture *texture, sf::Vector2f size,sf::Vector2f origin, sf::Vector2u imageCount ,float switchTime, float speed, float jumpHeight,int hearts,bool isAlive, bool isPlayer, bool isPlayerOne);
  ~Player();

  void Update(float deltaTime, Character* p);
  void GetDamage();
};
