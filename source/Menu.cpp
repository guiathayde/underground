#include "Menu.h"

Menu::Menu(float width, float height)
{
  selectedItemIndex = 1;
  isPlaying = false;
  isPaused = false;

  centerPosition.x = width / 2;
  centerPosition.y = height / 2;
}

Menu::~Menu()
{
}