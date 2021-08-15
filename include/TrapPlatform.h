#pragma once

#include "stdfix.h"
#include "Platform.h"

#define TRAP_PALTFORM_ID 8

class TrapPlatform : public Platform
{
private:
  sf::Vector2f velocity;

public:
  TrapPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~TrapPlatform();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};
