#pragma once

#include "ColliderManager.h"
#include "SaveManager.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "ModMenu.h"
#include "DynamicEntity.h"
#include "Chapters.h"
#include "Ranking.h"

class Game
{
private:
  GraphicManager *graphicManager;
  ColliderManager *colliderManager;
  SaveManager *saveManager;

  MainMenu *mainMenu;
  PauseMenu *pauseMenu;
  ModMenu *modMenu;
  Chapters *chapters;
  Ranking *ranking;
  Level *level;
  int levelNumber;

public:
  Game();
  ~Game();

  void Execute();
};
