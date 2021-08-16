#pragma once

#include "stdfix.h"
#include "Platform.h"

#define AIR_PLATFORM_ID 6

class AirPlatform : public Platform
{
private:

public:
  AirPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~AirPlatform();
};
