#pragma once

#include <SFML/Graphics.hpp>

class Collider
{
private:
  sf::RectangleShape &body;

public:
  Collider(sf::RectangleShape &body);
  ~Collider();

  void Move(float dx, float dy) const { body.move(dx, dy); }

  bool CheckCollision(const Collider &other, sf::Vector2f &direction, float push);
  sf::Vector2f GetPosition() const { return body.getPosition(); }
  sf::Vector2f GetHalfSize() const { return body.getSize() / 2.0f; }
};