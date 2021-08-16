#include "Chapters.h"
#include "GraphicManager.h"

Chapters::Chapters(GraphicManager *graphicManager) : Menu(graphicManager)
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

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  sf::FloatRect textRect;

  menu[0].setFont(font);
  menu[0].setCharacterSize(54);
  menu[0].setFillColor(sf::Color::White);
  menu[0].setString("Back");
  textRect = menu[0].getLocalBounds();
  menu[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[0].setPosition(windowSize.x / 2.0f, 100.0f);

  menu[1].setFont(font);
  menu[1].setCharacterSize(54);
  menu[1].setFillColor(sf::Color::Red);
  menu[1].setString("Sewer");
  textRect = menu[1].getLocalBounds();
  menu[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[1].setPosition(windowSize.x * 0.25f, 300.0f);

  sf::Texture *levelOneThumbTexture = graphicManager->GetTexture("levelOneThumbTexture");
  levelOneThumb.setSize(sf::Vector2f(300.0f, 150.0f));
  levelOneThumb.setTexture(levelOneThumbTexture);
  levelOneThumb.setOrigin(150.0f, 75.0f);
  levelOneThumb.setPosition(windowSize.x * 0.25f, 420.0f);

  menu[2].setFont(font);
  menu[2].setCharacterSize(54);
  menu[2].setFillColor(sf::Color::Black);
  menu[2].setString("Subway");
  textRect = menu[2].getLocalBounds();
  menu[2].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[2].setPosition(windowSize.x * 0.5f, 300.0f);

  sf::Texture *levelTwoThumbTexture = graphicManager->GetTexture("levelTwoThumbTexture");
  levelTwoThumb.setSize(sf::Vector2f(300.0f, 150.0f));
  levelTwoThumb.setTexture(levelTwoThumbTexture);
  levelTwoThumb.setOrigin(150.0f, 75.0f);
  levelTwoThumb.setPosition(windowSize.x * 0.5f, 420.0f);

  menu[3].setFont(font);
  menu[3].setCharacterSize(54);
  menu[3].setFillColor(sf::Color::Black);
  menu[3].setString("Overground");
  textRect = menu[3].getLocalBounds();
  menu[3].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  menu[3].setPosition(windowSize.x * 0.75f, 300.0f);

  sf::Texture *levelThreeThumbTexture = graphicManager->GetTexture("levelThreeThumbTexture");
  levelThreeThumb.setSize(sf::Vector2f(300.0f, 150.0f));
  levelThreeThumb.setTexture(levelThreeThumbTexture);
  levelThreeThumb.setOrigin(150.0f, 75.0f);
  levelThreeThumb.setPosition(windowSize.x * 0.75f, 420.0f);
}

Chapters::~Chapters()
{
}

void Chapters::Draw(sf::RenderWindow *window, sf::View *view)
{
  window->draw(background);
  window->draw(levelOneThumb);
  window->draw(levelTwoThumb);
  window->draw(levelThreeThumb);

  for (int i = 0; i < CHAPTERS_MAX_ITEMS; i++)
    window->draw(menu[i]);
}

void Chapters::MoveUp()
{
  if (selectedItemIndex - 1 >= 1)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void Chapters::MoveDown()
{
  if (selectedItemIndex + 1 < CHAPTERS_MAX_ITEMS)
  {
    menu[selectedItemIndex].setFillColor(sf::Color::Black);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void Chapters::MoveBack()
{
  for (int i = 1; i < CHAPTERS_MAX_ITEMS; i++)
    menu[i].setFillColor(sf::Color::Black);

  menu[0].setFillColor(sf::Color::Red);
  selectedItemIndex = 0;
}

void Chapters::MoveToSelection()
{
  menu[0].setFillColor(sf::Color::White);
  menu[1].setFillColor(sf::Color::Red);
  selectedItemIndex = 1;
}

int Chapters::SelectItem(sf::Event event, Level *level)
{
  switch (event.key.code)
  {
  case sf::Keyboard::Up:
    MoveBack();
    return -1;

  case sf::Keyboard::Down:
    MoveToSelection();
    return -1;

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

    case 2:
      return 2;

    case 3:
      return 3;

    default:
      return -1;
    }

  default:
    return -1;
  }
}