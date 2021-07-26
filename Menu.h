#pragma once

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
  Menu(float width, float height);
  ~Menu();

  void Draw(sf::RenderWindow &window);
  void MoveUp();
  void MoveDown();
};