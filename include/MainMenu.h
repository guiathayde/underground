#pragma once
#include "stdfx.h"

#define MAINMENU_MAX_ITEMS 5
#include "Menu.h"

class MainMenu : public Menu
{
private:
  
  sf::Font titleFont;
  sf::Font itemFont;
  sf::RectangleShape background;
  sf::Text menu[MAINMENU_MAX_ITEMS];

public:
  MainMenu(float width, float height);
  ~MainMenu();

  void Draw(sf::RenderWindow *window,sf::View *view);

  void MoveUp();
  void MoveDown();

  int SelectItem(sf::Event event, Level *level);
};