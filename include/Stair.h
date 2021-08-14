#pragma once

#include "stdfix.h"
#include "Item.h"

class Stair : public Item
{
private:
  bool isCaught;
  bool isStair;
  bool isDoor;

public:
  Stair(GraphicManager *graphciManager, sf::Vector2f position, int number);
  ~Stair();

  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  void SetCaught(bool state);
  bool GetCaught() { return isCaught; }

  void SetStair(bool state) { isStair = state; }
  bool GetStair() { return isStair; }

  void SetDoor(bool state) { isDoor = state; }
  bool GetDoor() { return isDoor; }

  void SetPosition(sf::Vector2f position) { body.setPosition(position); }
  sf::Vector2f GetPosition() { return body.getPosition(); }

  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};