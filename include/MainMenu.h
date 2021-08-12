#pragma once

#include "stdfx.h"
#include "Menu.h"

#define MAINMENU_MAX_ITEMS 5

class GraphicManager;
class MainMenu : public Menu
{
private:
  sf::Font titleFont;
  sf::Font itemFont;
  sf::RectangleShape background;
  sf::Text menu[MAINMENU_MAX_ITEMS];

public:
  MainMenu(GraphicManager *graphicManager);
  ~MainMenu();

  void Draw(sf::RenderWindow *window, sf::View *view);

  void MoveUp();
  void MoveDown();

  int SelectItem(sf::Event event, Level *level);
};