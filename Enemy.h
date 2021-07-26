#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Character.h"
#include "Player.h"

class Enemy: public Character
{
private:
  
public:
  Enemy(sf::Texture *texture, sf::Vector2u imageCount,sf::Vector2f origin, float switchTime, float speed,float jumpHeight);
  ~Enemy();
  void Update(float deltaTime,Player p);
  bool SeePlayer(Player p);
  float Attack(Player p);
};