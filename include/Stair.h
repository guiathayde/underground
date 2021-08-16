#pragma once

#include "stdfix.h"
#include "Item.h"

#define STAIR_ID 12

class Stair : public Item
{
private:
  int number;

public:
  Stair(GraphicManager *graphciManager, sf::Vector2f position, int number);
  ~Stair();

  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  bool GetCaught() { return isCaught; }
  int GetNumber() { return number; }

  void SetPosition(sf::Vector2f position) { body.setPosition(position); }
  sf::Vector2f GetPosition() { return body.getPosition(); }

  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};