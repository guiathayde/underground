#include <iostream>
using namespace std;

#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
  selectedItemIndex = 0;
  isPlaying = false;

  centerPosition.x = width / 2;
  centerPosition.y = height / 2;

  if (!titleFont.loadFromFile("assets/fonts/Aokigahara.ttf"))
    cerr << "Error loading title Aokigahara font!" << endl;

  if (!itemFont.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  if (!backgroundTexture.loadFromFile("assets/background/mainMenuBackground.png"))
    cerr << "Error loading background texture!" << endl;

  sf::FloatRect textRect;

  menu[0].setFont(titleFont);
  menu[0].setCharacterSize(104);
  menu[0].setFillColor(sf::Color::Black);
  menu[0].setString("Underground");
  textRect = menu[0].getLocalBounds();
  menu[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[0].setPosition(sf::Vector2f((width / 2) - 35.0f, height / (MAINMENU_MAX_ITEMS + 1) * 1.85));

  menu[1].setFont(itemFont);
  menu[1].setCharacterSize(54);
  menu[1].setFillColor(sf::Color::Red);
  menu[1].setString("Play");
  textRect = menu[1].getLocalBounds();
  menu[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[1].setPosition(sf::Vector2f(width / 2, height / (MAINMENU_MAX_ITEMS + 1) * 2.25));

  menu[2].setFont(itemFont);
  menu[2].setCharacterSize(54);
  menu[2].setFillColor(sf::Color::Black);
  menu[2].setString("Chapters");
  textRect = menu[2].getLocalBounds();
  menu[2].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[2].setPosition(sf::Vector2f(width / 2, height / (MAINMENU_MAX_ITEMS + 1) * 3.25));

  menu[3].setFont(itemFont);
  menu[3].setCharacterSize(54);
  menu[3].setFillColor(sf::Color::Black);
  menu[3].setString("Ranking");
  textRect = menu[3].getLocalBounds();
  menu[3].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[3].setPosition(sf::Vector2f(width / 2, height / (MAINMENU_MAX_ITEMS + 1) * 4.25));

  menu[4].setFont(itemFont);
  menu[4].setCharacterSize(54);
  menu[4].setFillColor(sf::Color::Black);
  menu[4].setString("Quit");
  textRect = menu[4].getLocalBounds();
  menu[4].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[4].setPosition(sf::Vector2f(width / 2, height / (MAINMENU_MAX_ITEMS + 1) * 5.25));
}

MainMenu::~MainMenu()
{
}

void MainMenu::Draw(sf::RenderWindow &window)
{
  sf::Vector2f rectangleSize = static_cast<sf::Vector2f>(window.getSize());
  background.setSize(rectangleSize);
  background.setTexture(&backgroundTexture);
  background.setOrigin(0.0f, 0.0f);
  window.draw(background);

  for (int i = 0; i < MAINMENU_MAX_ITEMS; i++)
    window.draw(menu[i]);
}

void MainMenu::MoveUp()
{
  if (selectedItemIndex - 1 >= 1)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void MainMenu::MoveDown()
{
  if (selectedItemIndex + 1 < MAINMENU_MAX_ITEMS)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void MainMenu::SelectItem(sf::Event event, sf::RenderWindow &window, Level &level)
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
    case 1:
      level.Initialize(2, window);
      SetPlaying(true);
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      level.ClearAll();
      window.close();
      break;

    default:
      break;
    }

  default:
    break;
  }
}