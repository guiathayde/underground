#pragma once

#include "DynamicEntityList.h"
#include "stdfx.h"
#include "Character.h"
#include "Platform.h"

class Player;
class ColliderManager
{
public:
  ColliderManager();
  ~ColliderManager();

  bool CheckCollision(sf::RectangleShape &body, sf::RectangleShape &otherBody, sf::Vector2f &direction, float push);
  bool CheckOnHeadCollision(sf::RectangleShape &body, sf::RectangleShape &otherBody);

  void OnCollision(sf::Vector2f direction, DynamicEntity *character);
  void CheckEntitiesCollison(DynamicEntityList *entities, list<Obstacle *> platforms, list<Character *> character);
  void CheckPlayerOnHead(list<Character *> characters, Player *playerOne, Player *playerTwo);
};