#pragma once

#include "stdfix.h"
#include "Platform.h"

#define BASE_PLATFORM_ID 7

class BasePlatform : public Platform
{
private:

public:
  BasePlatform(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position);
  ~BasePlatform();
};
