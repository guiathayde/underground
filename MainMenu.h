#pragma once

#include <SFML/Graphics.hpp>

#include "Level.h"

#define MAINMENU_MAX_ITEMS 5

class MainMenu
{
private:
  int selectedItemIndex;
  bool isPlaying;

  sf::Vector2f centerPosition;
  sf::Font titleFont;
  sf::Font itemFont;
  sf::Texture backgroundTexture;
  sf::RectangleShape background;
  sf::Text menu[MAINMENU_MAX_ITEMS];

public:
  MainMenu(float width, float height);
  ~MainMenu();

  void Draw(sf::RenderWindow &window);
  void MoveUp();
  void MoveDown();
  void SelectItem(sf::Event event, sf::RenderWindow &window, Level &level);

  int GetPressedItem() { return selectedItemIndex; }

  void SetPlaying(bool state) { isPlaying = state; }
  bool GetPlaying() { return isPlaying; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};