#include <iostream>
using namespace std;

#include "PauseMenu.h"

PauseMenu::PauseMenu(float width, float height)
{
  selectedItemIndex = 0;
  isPaused = false;

  centerPosition.x = width / 2;
  centerPosition.y = height / 2;

  if (!font.loadFromFile("assets/Quicksand.ttf"))
    cerr << "Error loading font!" << endl;

  menu[0].setFont(font);
  menu[0].setFillColor(sf::Color::Red);
  menu[0].setString("Play");
  menu[0].setPosition(sf::Vector2f(width / 3, height / (MENU_MAX_ITEMS + 1) * 1));

  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Options");
  menu[1].setPosition(sf::Vector2f(width / 3, height / (MENU_MAX_ITEMS + 1) * 2));

  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Exit");
  menu[2].setPosition(sf::Vector2f(width / 3, height / (MENU_MAX_ITEMS + 1) * 3));
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(sf::RenderWindow &window)
{
  for (int i = 0; i < MENU_MAX_ITEMS; i++)
  {
    window.draw(menu[i]);
  }
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

void PauseMenu::SelectItem(sf::Event event, sf::RenderWindow &window)
{
  switch (event.key.code)
  {
  case sf::Keyboard::Up:
    MoveUp();
    break;

  case sf::Keyboard::Down:
    MoveDown();
    break;

  case sf::Keyboard::Return:
    switch (GetPressedItem())
    {
    case 0:
      cout << "Play pressed!" << endl;
      SetPause(false);
      break;

    case 1:
      cout << "Options pressed!" << endl;
      break;

    case 2:
      cout << "Quit pressed!" << endl;
      window.close();
      break;

    default:
      break;
    }

  case sf::Mouse::Left:
  {
    sf::Vector2i position = sf::Mouse::getPosition();
    // explanation of this conditionals: https://en.sfml-dev.org/forums/index.php?topic=21666.0
    bool firstOption = menu[0].getGlobalBounds().contains(window.mapPixelToCoords(position));
    bool secondOption = menu[1].getGlobalBounds().contains(window.mapPixelToCoords(position));
    bool thirdOption = menu[2].getGlobalBounds().contains(window.mapPixelToCoords(position));

    cout << "Mouse position: " << position.x << ", " << position.y << endl;
    cout << firstOption << " " << secondOption << " " << thirdOption << endl;

    if (firstOption)
    {
      cout << "Play pressed!" << endl;
      SetPause(false);
    }
    else if (secondOption)
    {
      cout << "Options pressed!" << endl;
    }
    else if (thirdOption)
    {
      cout << "Quit pressed!" << endl;
      window.close();
    }

    break;
  }

  default:
    break;
  }
}