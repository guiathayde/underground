#pragma once

#include "stdfx.h"
#include "DynamicEntityList.h"
#include "Character.h"
#include "Platform.h"

class Player;
class Item;
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
  void CheckItemCollision(list<Item *> items, Player *playerOne, Player *playerTwo);
};