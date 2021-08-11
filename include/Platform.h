#pragma once

#include "stdfix.h"
#include "Obstacle.h"

class Platform : public Obstacle
{
private:
  sf::Vector2f velocity;

public:
  Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
  ~Platform();

  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};