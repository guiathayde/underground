#pragma once

#include "stdfix.h"
#include "Platform.h"

class BasePlatform : public Platform
{
private:
  sf::Vector2f velocity;

public:
  BasePlatform(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position);
  ~BasePlatform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
