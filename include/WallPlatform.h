#pragma once

#include "stdfix.h"
#include "Platform.h"

#define WALL_PLATFORM_ID 9

class WallPlatform : public Platform
{
private:
  sf::Vector2f velocity;

public:
  WallPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~WallPlatform();
};
