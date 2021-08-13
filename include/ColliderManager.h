#pragma once

#include "stdfx.h"


class Platform;
class Character;
class Player;
class DynamicEntityList;
class DynamicEntity;
class Obstacle;

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