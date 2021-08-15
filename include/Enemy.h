#pragma once

#include "stdfx.h"
#include "Player.h"

class Enemy : public Character
{
protected:
  
  bool isStunned;
  float coolDown;
  float totalStunTime;

public:
  Enemy(GraphicManager* graphicManager,sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight,float totalStunTime,int id,int hearts, bool isAlive, bool isPlayer);
  ~Enemy();

  void Update(float deltaTime, Character *p);
  bool SeePlayer(Player p);
  float Attack(Player p);

  void SetStunned() { isStunned = true; };
  bool GetStunned() { return isStunned; }
};