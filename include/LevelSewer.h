#pragma once

#include "Level.h"
#include "GraphicManager.h"

class LevelSewer : public Level
{
private:
  int enemiesNum;
  GraphicManager *graphicManager;

public:
  LevelSewer(GraphicManager *graphicManager);
  ~LevelSewer();

  void Initialize();
  float GetSizeX() { return sizeX; }
};