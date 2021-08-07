#pragma once

#include "stdfx.h"
#include "Player.h"
class Enemy : public Character
{
private:
  bool isStunned;
  float coolDown;
  const float totalStunTime;

public:
  Enemy(sf::Texture *texture, sf::Vector2f size, sf::Vector2f origin, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float totalStunTime, int hearts, bool isAlive, bool isPlayer);
  ~Enemy();

  void Update(float deltaTime, Character *p);
  void SetPosition(sf::Vector2f position);
  bool SeePlayer(Player p);
  float Attack(Player p);
};