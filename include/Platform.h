#pragma once

#include "stdfix.h"
#include "Obstacle.h"

class Platform : public Obstacle
{
private:
  sf::Vector2f velocity;

public:
  Platform(GraphicManager *graphicManager, sf::Vector2f position);
  ~Platform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
