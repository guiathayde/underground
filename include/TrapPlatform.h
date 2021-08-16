#pragma once

#include "stdfix.h"
#include "Platform.h"

#define TRAP_PALTFORM_ID 8

class TrapPlatform : public Platform
{
private:

public:
  TrapPlatform(GraphicManager *graphicManager, sf::Vector2f position);
  ~TrapPlatform();
};
