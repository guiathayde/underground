#pragma once 
#include "Obstacle.h"

#define SPIKE_ID 10

class Spike:public Obstacle
{
private:

public:
  Spike(GraphicManager *graphicManager, sf::Vector2f position);
  ~Spike();

  void Draw(sf::RenderWindow &window);
  void Update(float deltaTime, Character *character);
  void OnCollision(sf::Vector2f direction);

  sf::Vector2f GetPosition() { return body.getPosition(); }
  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();
};



