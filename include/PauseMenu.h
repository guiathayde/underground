#pragma once

#include "stdfx.h"
#include "Menu.h"

#define MENU_MAX_ITEMS 2

class GraphicManager;
class Level;

class PauseMenu : public Menu
{
private:
  sf::Font font;
  sf::Text menu[MENU_MAX_ITEMS];

public:
  PauseMenu(GraphicManager *graphicManager);
  ~PauseMenu();

  void Draw(sf::RenderWindow *window, sf::View *view);
  void MoveUp();
  void MoveDown();
  int SelectItem(sf::Event event, Level *level);
};