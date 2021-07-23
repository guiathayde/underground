#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Enemy
{
private:
  sf::RectangleShape body;
  Animation animation;
  unsigned int row;
  float speed;
  bool faceRight;

public:
  Enemy(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
  ~Enemy();

  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
};