#pragma once

#include "stdfix.h"
#include "Obstacle.h"

class Platform : public Obstacle
{
protected:
  bool isTrap;

public:
  Platform(GraphicManager *graphicManager, sf::Vector2f position, int id);
  ~Platform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  bool GetIsTrap() { return isTrap; }

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
