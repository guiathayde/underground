#pragma once

#include <SFML/Graphics.hpp>

class ManagerAnimation
{
private:
  
  sf::Vector2u imageCount;
  sf::Vector2f currentImage;

  float totalTime;
  float switchTime;

public:
  sf::IntRect uvRect;

public:
  ManagerAnimation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
  ~ManagerAnimation();

  void Update(int row, float deltaTime, bool faceRight);
};