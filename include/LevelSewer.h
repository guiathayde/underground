#pragma once

#include "Level.h"

class LevelSewer : public Level
{
private:
  int enemiesNum;

public:
  LevelSewer(GraphicManager *graphicManager, ColliderManager *graphicCollider);
  ~LevelSewer();

  void InitializeCharacters(DynamicEntityList* entities);
  void Initialize(DynamicEntityList* entities);

  float GetSizeX() { return sizeX; }
};