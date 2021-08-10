#include <iostream>
using namespace std;

#include "PauseMenu.h"
#include "Level.h"

PauseMenu::PauseMenu(float width, float height) : Menu(width, height)
{
  selectedItemIndex = 0;
  isPaused = false;

  centerPosition.x = width / 2;
  centerPosition.y = height / 2;

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading DarkMage font!" << endl;

  menu[0].setFont(font);
  menu[0].setCharacterSize(64);
  menu[0].setFillColor(sf::Color::Red);
  menu[0].setString("Return to the game");

  menu[1].setFont(font);
  menu[1].setCharacterSize(64);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Back to main menu");
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(sf::RenderWindow *window, sf::View *view)
{
  menu[0].setPosition(view->getCenter().x - 500.0f, view->getCenter().y - 200.0f);
  menu[1].setPosition(view->getCenter().x - 500.0f, view->getCenter().y - 100.0f);

  for (int i = 0; i < MENU_MAX_ITEMS; i++)
    window->draw(menu[i]);
}

void PauseMenu::MoveUp()
{
  if (selectedItemIndex - 1 >= 0)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void PauseMenu::MoveDown()
{
  if (selectedItemIndex + 1 < MENU_MAX_ITEMS)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

int PauseMenu::SelectItem(sf::Event event, Level *level)
{
  switch (event.key.code)
  {
  case sf::Keyboard::Up:
    MoveUp();
    return -1;

  case sf::Keyboard::Down:
    MoveDown();
    return -1;

  case sf::Keyboard::Return:
    switch (GetPressedItem())
    {
    case 0:
      return 0;

    case 1:
      return 1;

    default:
      return -1;
    }

  default:
    return -1;
  }
  
  return -1;
}