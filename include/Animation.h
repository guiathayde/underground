#pragma once 

#include "stdfx.h"


class Animation
{
private:
  
  sf::Vector2u imageCount;
  sf::Vector2f currentImage;

  float totalTime;
  float switchTime;

public:
  sf::IntRect uvRect;

public:
  Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
  ~Animation();

  void Update(int row, float deltaTime, bool faceRight);
};