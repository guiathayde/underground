#pragma once

#include "GraphicManager.h"
#include "ColliderManager.h"
#include "SaveManager.h"
#include "MainMenu.h"
#include "PauseMenu.h"
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
  Chapters *chapters;
  Ranking *ranking;
  Level *level;

public:
  Game();
  ~Game();

  void Execute();
};
