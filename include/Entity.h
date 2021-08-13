#pragma once 

#include "stdfx.h"
#include "GraphicManager.h"

class Entity
{
protected:
  
  GraphicManager* graphicManager;

public:
  Entity(GraphicManager* graphicManager);
  ~Entity();

  virtual void Draw(sf::RenderWindow &window) = 0;
};
