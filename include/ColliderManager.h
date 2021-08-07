#pragma once

#include "stdfx.h"

class ColliderManager
{
private:
  sf::RectangleShape &body;

public:
  ColliderManager(sf::RectangleShape &body);
  ~ColliderManager();

  void Move(float dx, float dy) const { body.move(dx, dy); }

  bool CheckCollision(const ColliderManager &other, sf::Vector2f &direction, float push);
  bool CheckOnHeadCollision(const ColliderManager &other, sf::Vector2f &direction, float push);

  sf::Vector2f GetPosition() const { return body.getPosition(); }
  sf::Vector2f GetHalfSize() const { return body.getSize() / 2.0f; }
};