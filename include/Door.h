#pragma once

#include "stdfix.h"
#include "Item.h"

#define DOOR_ID 11

class Door : public Item
{
private:
public:
  Door(GraphicManager *graphciManager, sf::Vector2f position);
  ~Door();

  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  int GetNumber() { return 0; }
  void SetPosition(sf::Vector2f position) { body.setPosition(position); }
  sf::Vector2f GetPosition() { return body.getPosition(); }

  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};