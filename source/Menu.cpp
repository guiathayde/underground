#include "Menu.h"
#include "GraphicManager.h"

Menu::Menu(GraphicManager *graphicManager) : Entity(graphicManager)
{
  selectedItemIndex = 1;
  isPlaying = false;
  isPaused = false;

  sf::Vector2f windowSize = static_cast<sf::Vector2f>(graphicManager->GetWindow()->getSize());

  centerPosition.x = windowSize.x / 2.0f;
  centerPosition.y = windowSize.y / 2.0f;
}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow &window)
{
}