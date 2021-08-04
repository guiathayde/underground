#pragma once

#include "GraphicManager.h"

class Game : public GraphicManager
{
private:
  GraphicManager *graphicManager;

public:
  Game();
  ~Game();

  void Execute();
};
