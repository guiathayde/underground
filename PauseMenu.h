#pragma once

#include <SFML/Graphics.hpp>

#define MENU_MAX_ITEMS 3

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

  void Draw(sf::RenderWindow &window);
  void MoveUp();
  void MoveDown();
  void SelectItem(sf::Event event, sf::RenderWindow &window);

  int GetPressedItem() { return selectedItemIndex; }

  void SetPause(bool state) { isPaused = state; }
  bool GetPause() { return isPaused; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};