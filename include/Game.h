#pragma once

#include "ColliderManager.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "DynamicEntity.h"
#include "Chapters.h"

class Game
{
private:
    GraphicManager *graphicManager;
  ColliderManager *colliderManager;

  MainMenu *mainMenu;
  PauseMenu *pauseMenu;
  Chapters *chapters;
  Level *level;

public:
  Game();
  ~Game();

  void Execute();
};
