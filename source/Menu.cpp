#include "Menu.h"

Menu::Menu(GraphicManager* graphicManager,float width, float height):Entity(graphicManager)
{
  selectedItemIndex = 1;
  isPlaying = false;
  isPaused = false;

  centerPosition.x = width / 2;
  centerPosition.y = height / 2;
}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow &window){

}