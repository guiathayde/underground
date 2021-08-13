#pragma once

#include "ColliderManager.h"

#include "MainMenu.h"
#include "PauseMenu.h"
#include "LevelSewer.h"
#include "DynamicEntity.h"

class Game
{
private:
  
  GraphicManager *graphicManager;
  ColliderManager *colliderManager;

  MainMenu *mainMenu;
  PauseMenu *pauseMenu;
  Level *level;

public:
  Game();
  ~Game();

  void Execute();
};
