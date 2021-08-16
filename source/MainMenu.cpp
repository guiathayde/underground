#include "MainMenu.h"
#include "Level.h"
#include "GraphicManager.h"

MainMenu::MainMenu(GraphicManager *graphicManager) : Menu(graphicManager)
{
  selectedItemIndex = 1;
  isPlaying = false;
  isPaused = false;
  isChapters = false;
  isRanking = false;
  isModMenu = false;

  sf::Vector2f windowSize = static_cast<sf::Vector2f>(graphicManager->GetWindow()->getSize());

  centerPosition.x = windowSize.x / 2.0f;
  centerPosition.y = windowSize.y / 2.0f;

  sf::Texture *backgroundTexture = graphicManager->GetTexture("mainMenuBackgroundTexture");
  background.setSize(windowSize);
  background.setTexture(backgroundTexture);
  background.setOrigin(0.0f, 0.0f);

  if (!titleFont.loadFromFile("assets/fonts/Aokigahara.ttf"))
    cerr << "Error loading title Aokigahara font!" << endl;

  if (!itemFont.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  sf::FloatRect textRect;

  menu[0].setFont(titleFont);
  menu[0].setCharacterSize(104);
  menu[0].setFillColor(sf::Color::Black);
  menu[0].setString("Underground");
  textRect = menu[0].getLocalBounds();
  menu[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[0].setPosition(sf::Vector2f((windowSize.x / 2) - 35.0f, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 1.85));

  menu[1].setFont(itemFont);
  menu[1].setCharacterSize(54);
  menu[1].setFillColor(sf::Color::Red);
  menu[1].setString("Play");
  textRect = menu[1].getLocalBounds();
  menu[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[1].setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 2.25));

  menu[2].setFont(itemFont);
  menu[2].setCharacterSize(54);
  menu[2].setFillColor(sf::Color::Black);
  menu[2].setString("Load Game");
  textRect = menu[2].getLocalBounds();
  menu[2].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[2].setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 3.25));

  menu[3].setFont(itemFont);
  menu[3].setCharacterSize(54);
  menu[3].setFillColor(sf::Color::Black);
  menu[3].setString("Chapters");
  textRect = menu[3].getLocalBounds();
  menu[3].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[3].setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 4.25));

  menu[4].setFont(itemFont);
  menu[4].setCharacterSize(54);
  menu[4].setFillColor(sf::Color::Black);
  menu[4].setString("Ranking");
  textRect = menu[4].getLocalBounds();
  menu[4].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[4].setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 5.25));

  menu[5].setFont(itemFont);
  menu[5].setCharacterSize(54);
  menu[5].setFillColor(sf::Color::Black);
  menu[5].setString("Quit");
  textRect = menu[5].getLocalBounds();
  menu[5].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[5].setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / (MAINMENU_MAX_ITEMS + 1) * 6.25));
}

MainMenu::~MainMenu()
{
  delete (backgroundTexture);
}

void MainMenu::Draw(sf::RenderWindow *window, sf::View *view)
{
  window->draw(background);

  for (int i = 0; i < MAINMENU_MAX_ITEMS; i++)
    window->draw(menu[i]);
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

int MainMenu::SelectItem(sf::Event event, Level *level)
{
  switch (event.key.code)
  {
  case sf::Keyboard::Up:
    MoveUp();
    return 0;

  case sf::Keyboard::Down:
    MoveDown();
    return 0;

  case sf::Keyboard::Return:
    switch (GetPressedItem())
    {
    case 1:
      return 1;

    case 2:
      return 2;

    case 3:
      return 3;

    case 4:
      return 4;

    case 5:
      return 5;

    default:
      return 0;
    }

  default:
    return 0;
  }
}