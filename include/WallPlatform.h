#pragma once

#include "stdfix.h"
#include "Platform.h"

class WallPlatform : public Platform
{
private:
  sf::Vector2f velocity;

public:
  WallPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~WallPlatform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
