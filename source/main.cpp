#include "stdfx.h"
#include "Game.h"

int main()
{
  srand(time(NULL));
  Game game;
  game.Execute();

  return 0;
}