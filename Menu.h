#pragma once

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
  int selectedItemIndex;
  bool isPaused;

  sf::Vector2f centerPosition;
  sf::Font font;
  sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
  Menu(float width, float height);
  ~Menu();

  void Draw(sf::RenderWindow &window);
  void MoveUp();
  void MoveDown();
  void SelectItem(sf::Event event, sf::RenderWindow &window);

  int GetPressedItem() { return selectedItemIndex; }

  void SetPause(bool state) { isPaused = state; }
  bool GetPause() { return isPaused; }

  sf::Vector2f GetCenterPosition() { return centerPosition; }
};