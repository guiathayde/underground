#include "ModMenu.h"
#include "GraphicManager.h"

ModMenu::ModMenu(GraphicManager *graphicManager) : Menu(graphicManager)
{
  selectedItemIndex = 0;
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

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  sf::FloatRect textRect;

  menu[0].setFont(font);
  menu[0].setCharacterSize(58);
  menu[0].setFillColor(sf::Color::Red);
  menu[0].setString("Solo");
  textRect = menu[0].getLocalBounds();
  menu[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[0].setPosition(windowSize.x * 0.333f, graphicManager->GetWindow()->getSize().y / 2.0f);

  menu[1].setFont(font);
  menu[1].setCharacterSize(58);
  menu[1].setFillColor(sf::Color::Black);
  menu[1].setString("co-op");
  textRect = menu[1].getLocalBounds();
  menu[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[1].setPosition(windowSize.x * 0.666f, graphicManager->GetWindow()->getSize().y / 2.0f);
}

ModMenu::~ModMenu()
{
}

void ModMenu::Draw(sf::RenderWindow *window, sf::View *view)
{
  window->draw(background);

  for (int i = 0; i < MODMENU_MAX_ITEMS; i++)
    window->draw(menu[i]);
}

void ModMenu::MoveUp()
{
  if (selectedItemIndex - 1 >= 0)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void ModMenu::MoveDown()
{
  if (selectedItemIndex + 1 < MODMENU_MAX_ITEMS)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

int ModMenu::SelectItem(sf::Event event, Level *level)
{
  switch (event.key.code)
  {
  case sf::Keyboard::Left:
    MoveUp();
    return -1;

  case sf::Keyboard::Right:
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
}

bool ModMenu::SelectMod(sf::RenderWindow *window, sf::View *view, sf::Event event, Level *level)
{
  int choise = -1;

  while (choise != 1 || choise != 0)
  {
    Draw(window, view);

    choise = SelectItem(event, level);

    return choise == 1 ? true : false;
  }
  return false;
}