#include "Ranking.h"
#include "GraphicManager.h"

Ranking::Ranking(GraphicManager *graphicManager) : Menu(graphicManager)
{
  selectedItemIndex = 0;
  sizeWithRank = 0;
  isPlaying = false;
  isPaused = false;
  isChapters = false;
  isRanking = false;

  sf::Vector2f windowSize = static_cast<sf::Vector2f>(graphicManager->GetWindow()->getSize());

  centerPosition.x = windowSize.x / 2.0f;
  centerPosition.y = windowSize.y / 2.0f;

  sf::Texture *backgroundTexture = graphicManager->GetTexture("ranking");
  background.setSize(windowSize);
  background.setTexture(backgroundTexture);
  background.setOrigin(0.0f, 0.0f);

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  sf::FloatRect textRect;

  back[0].setFont(font);
  back[0].setCharacterSize(54);
  back[0].setFillColor(sf::Color::White);
  back[0].setString("Back");
  textRect = back[0].getLocalBounds();
  back[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  back[0].setPosition(windowSize.x / 2.0f, 50.0f);

  for (int i = 1; i < RANK_MAX_SIZE; i++)
  {
    name[i].setFont(font);
    name[i].setCharacterSize(44);
    name[i].setFillColor(sf::Color::White);
    textRect = name[i].getLocalBounds();
    name[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    name[i].setPosition((windowSize.x / 3.0f) - 60.0f, i * 100.0f);

    score[i].setFont(font);
    score[i].setCharacterSize(44);
    score[i].setFillColor(sf::Color::White);
    textRect = score[i].getLocalBounds();
    score[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    score[i].setPosition(windowSize.x / 2.0f + 50.0f, i * 100.0f);
  }
}

Ranking::~Ranking()
{
}

void Ranking::Draw(sf::RenderWindow *window, sf::View *view)
{
  window->draw(background);
  window->draw(back[0]);

  map<string, int>::iterator it = ranking.begin();
  for (int i = 1, j = 0; j < sizeWithRank; i++, j++, it++)
  {
    name[i].setString(it->first);
    string scoreString = to_string(it->second);
    score[i].setString(scoreString);
  }

  for (int i = 1, j = 0; j < sizeWithRank; i++, j++)
  {
    window->draw(name[i]);
    window->draw(score[i]);
  }
}

void Ranking::MoveUp()
{
  back[0].setFillColor(sf::Color::Red);
}

void Ranking::MoveDown()
{
  back[0].setFillColor(sf::Color::White);
}

void Ranking::SetRank(string name, int score)
{
  bool isInserted = false;

  map<string, int>::iterator it;
  for (it = ranking.begin(); it != ranking.end(); it++)
    if (it->first == name)
    {
      it->second += score;
      isInserted = true;
    }

  if (!isInserted)
  {
    ranking.emplace(name, score);
    sizeWithRank++;
  }
}

int Ranking::SelectItem(sf::Event event, Level *level)
{
  if (event.key.code == sf::Keyboard::Up)
  {
    MoveUp();
    return -1;
  }
  if (event.key.code == sf::Keyboard::Down)
  {
    MoveDown();
    return -1;
  }
  if (event.key.code == sf::Keyboard::Return && back[0].getFillColor() == sf::Color::Red)
    return 0;

  return -1;
}