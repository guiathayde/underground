#pragma once

#include "stdfx.h"
#include "Menu.h"

#define MODMENU_MAX_ITEMS 2

class GraphicManager;
class ModMenu : public Menu
{
private:
  sf::RectangleShape background;
  sf::Font font;
  sf::Text menu[MODMENU_MAX_ITEMS];

public:
  ModMenu(GraphicManager *graphicManager);
  ~ModMenu();

  void Draw(sf::RenderWindow *window, sf::View *view);

  void MoveUp();
  void MoveDown();

  int SelectItem(sf::Event event, Level *level);

  bool SelectMod(sf::RenderWindow *window, sf::View *view, sf::Event event, Level *level);
};