#pragma once

#include "Level.h"

class LevelSewer : public Level
{
private:
  int enemiesNum;
  sf::Vector2f basePlatformPosition;

public:
  LevelSewer(GraphicManager *graphicManager, ColliderManager *graphicCollider, bool isCoop);
  ~LevelSewer();

  void InitializeCharacters();
  void Initialize();

  float GetSizeX() { return sizeX; }
};