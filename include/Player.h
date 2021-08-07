#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "stdfix.h"
#include "Character.h"

class Player : public Character
{
private:
  bool isPlayerOne;

public:
  Player(sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int hearts, bool isAlive, bool isPlayer, bool isPlayerOne);
  ~Player();

  void Update(float deltaTime, Character *p);
  void SetPosition(sf::Vector2f position) { body.setPosition(position); }
  int GetHearts(){return hearts;}
  void GetDamage();
};
