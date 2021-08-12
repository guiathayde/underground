#pragma once

#include "stdfx.h"
#include "Menu.h"

#define CHAPTERS_MAX_ITEMS 4

class GraphicManager;
class Chapters : public Menu
{
private:
  sf::Font font;

  sf::RectangleShape background;
  sf::RectangleShape levelOneThumb;
  sf::RectangleShape levelTwoThumb;
  sf::RectangleShape levelThreeThumb;

  sf::Text menu[CHAPTERS_MAX_ITEMS];

public:
  Chapters(GraphicManager *graphicManager);
  ~Chapters();

  void Draw(sf::RenderWindow *window, sf::View *view);

  void MoveUp();
  void MoveDown();
  void MoveBack();
  void MoveToSelection();

  int SelectItem(sf::Event event, Level *level);
};