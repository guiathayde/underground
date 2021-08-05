#pragma once

#include "GraphicManager.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "LevelSewer.h"

class Game
{
private:
  
  GraphicManager *graphicManager;
  MainMenu *mainMenu;
  PauseMenu *pauseMenu;

public:
  Game();
  ~Game();

  void Execute();
};
