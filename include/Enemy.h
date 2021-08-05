#pragma once

#include "stdfx.h"
#include "Player.h"
class Enemy: public Character
{
private:

public:
  Enemy(sf::Texture *texture, sf::Vector2f size,sf::Vector2f origin,sf::Vector2u imageCount, float switchTime, float speed,float jumpHeight,int hearts,bool isAlive,bool isPlayer);
  ~Enemy();
  
  void Update(float deltaTime, Character* p);
  bool SeePlayer(Player p);
  float Attack(Player p);
};