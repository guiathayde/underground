#pragma once

#include "stdfx.h"



#define MENU_MAX_ITEMS 2
class MainMenu;
class Level;

class PauseMenu
{
private:
  int selectedItemIndex;
  bool isPaused;

  sf::Vector2f centerPosition;
  sf::Font font;
  sf::Text menu[MENU_MAX_ITEMS];

public:
  PauseMenu(float width, float height);
  ~PauseMenu();

  void Draw(sf::RenderWindow &window, sf::View &view);
  void MoveUp();
  void MoveDown();
  void SelectItem(sf::Event event, MainMenu &mainMenu, Level &level);

  int GetPressedItem() { return selectedItemIndex; }

  void SetPause(bool state) { isPaused = state; }
  bool GetPause() { return isPaused; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};