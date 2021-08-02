#pragma once

#include <SFML/Graphics.hpp>

class ManagerCollider
{
private:
  sf::RectangleShape &body;

public:
  ManagerCollider(sf::RectangleShape &body);
  ~ManagerCollider();

  void Move(float dx, float dy) const { body.move(dx, dy); }

  bool CheckCollision(const ManagerCollider &other, sf::Vector2f &direction, float push);
  sf::Vector2f GetPosition() const { return body.getPosition(); }
  sf::Vector2f GetHalfSize() const { return body.getSize() / 2.0f; }
};