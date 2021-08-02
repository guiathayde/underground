#pragma once

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Obstacle.h"

class Platform:public Obstacle
{ 
private:

sf::Vector2f velocity;

public:
  
  Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
  ~Platform();

  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  Collider GetCollider(){return Collider(body);}
};