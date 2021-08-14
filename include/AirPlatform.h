#pragma once

#include "stdfix.h"
#include "Platform.h"

class AirPlatform : public Platform
{
private:
  sf::Vector2f velocity;

public:
  AirPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~AirPlatform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
