#include "stdfx.h"
#include "Level.h"
#include "Player.h"
#include "Obstacle.h"
#include "GraphicManager.h"
#include "ColliderManager.h"
#include "Item.h"
#include "Ranking.h"

Level::Level(GraphicManager *graphicManager, ColliderManager *colliderManager) : Entity(graphicManager), colliderManager(colliderManager)
{
  n_entities = 0;
  score = 0;
  nextLevel = 0;
  endLevel = false;
  name = "";
  finalPhrase = "";

  sizeX = 5000.0f;

  this->graphicManager = graphicManager;

  view = graphicManager->GetView();
  window = graphicManager->GetWindow();

  entities = new DynamicEntityList();

  sf::Texture *endLevelBackgroundTexture = graphicManager->GetTexture("endLevelBackground");
  endLevelBackground.setSize(static_cast<sf::Vector2f>(graphicManager->GetWindow()->getSize()));
  endLevelBackground.setOrigin(endLevelBackground.getSize() / 2.0f);
  endLevelBackground.setTexture(endLevelBackgroundTexture);

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

  /* ----------------------------------------------- SetUp Score Display -----------------------------------------------*/
  scoreText[0].setFont(font);
  scoreText[0].setCharacterSize(48);
  scoreText[0].setFillColor(sf::Color::White);
  scoreText[0].setString("Score: ");
  sf::FloatRect textRectScore = scoreText[0].getLocalBounds();
  scoreText[0].setOrigin(0.0f, 0.0f);
  scoreText[0].setPosition(20.0f, 40.0f);

  scoreText[1].setFont(font);
  scoreText[1].setCharacterSize(48);
  scoreText[1].setFillColor(sf::Color::White);
  scoreText[1].setString("0");
  sf::FloatRect textRectInt = scoreText[1].getLocalBounds();
  scoreText[1].setOrigin(0.0f, 0.0f);
  scoreText[1].setPosition(textRectScore.width + 15.0f, 40.0f);

  /* ----------------------------------------------- SetUp Health Display -----------------------------------------------*/
  heartsText[0].setFont(font);
  heartsText[0].setCharacterSize(48);
  heartsText[0].setFillColor(sf::Color::White);
  heartsText[0].setString(to_string(hearts));
  sf::FloatRect textRectHealthInt = heartsText[0].getLocalBounds();
  heartsText[0].setOrigin(0.0f, 0.0f);
  heartsText[0].setPosition((window->getSize().x / 2.0f) - 50.0f, 40.0f);

  heartsText[1].setFont(font);
  heartsText[1].setCharacterSize(48);
  heartsText[1].setFillColor(sf::Color::White);
  heartsText[1].setString("/300");
  sf::FloatRect textRectHealthTotal = heartsText[1].getLocalBounds();
  heartsText[1].setOrigin(0.0f, 0.0f);
  heartsText[1].setPosition((window->getSize().x / 2.0f) + 50.0f, 40.0f);

  healthBox.setSize(sf::Vector2f(150.0f, 50.0f));
  healthBox.setPosition((window->getSize().x / 2.0f) - 50.0f, 40.0f);
  healthBox.setFillColor(sf::Color::Red);

  /* ----------------------------------------------- SetUp End Level Display -----------------------------------------------*/
  endLevelText[0].setFont(font);
  endLevelText[0].setCharacterSize(56);
  endLevelText[0].setFillColor(sf::Color::White);
  endLevelText[0].setString("Congratulation!");
  sf::FloatRect textRectEndLevelCongratulation = endLevelText[0].getLocalBounds();
  endLevelText[0].setOrigin(textRectEndLevelCongratulation.left + textRectEndLevelCongratulation.width / 2.0f, textRectEndLevelCongratulation.top + textRectEndLevelCongratulation.height / 2.0f);
  endLevelText[0].setPosition(static_cast<float>(graphicManager->GetWindow()->getSize().x) / 2.0f, 40.0f);

  endLevelText[1].setFont(font);
  endLevelText[1].setCharacterSize(44);
  endLevelText[1].setFillColor(sf::Color::White);
  endLevelText[1].setString(finalPhrase);
  sf::FloatRect textRectEndLevelPhrase = endLevelText[1].getLocalBounds();
  endLevelText[1].setOrigin(textRectEndLevelPhrase.left + textRectEndLevelPhrase.width / 2.0f, textRectEndLevelPhrase.top + textRectEndLevelPhrase.height / 2.0f);
  endLevelText[1].setPosition(static_cast<float>(graphicManager->GetWindow()->getSize().x) / 2.0f, 40.0f + textRectEndLevelCongratulation.height);

  for (int i = 2, j = 3; i <= 3; i++, j--)
  {
    endLevelText[i].setFont(font);
    endLevelText[i].setCharacterSize(48);
    endLevelText[i].setFillColor(sf::Color::White);
    sf::FloatRect textRectEndLevelPhrase = endLevelText[i].getLocalBounds();
    endLevelText[i].setOrigin(textRectEndLevelPhrase.left + textRectEndLevelPhrase.width / 2.0f, textRectEndLevelPhrase.top + textRectEndLevelPhrase.height / 2.0f);
    endLevelText[i].setPosition(static_cast<float>(graphicManager->GetWindow()->getSize().x) / (float)j, static_cast<float>(graphicManager->GetWindow()->getSize().y) / 2.0f);
  }
  endLevelText[2].setFillColor(sf::Color::Red);

  endLevelText[4].setFont(font);
  endLevelText[4].setCharacterSize(52);
  endLevelText[4].setFillColor(sf::Color::White);
  endLevelText[4].setString("Continue");
  sf::FloatRect textRectEndLevelContinue = endLevelText[4].getLocalBounds();
  endLevelText[4].setOrigin(textRectEndLevelContinue.left + textRectEndLevelContinue.width / 2.0f, textRectEndLevelContinue.top + textRectEndLevelContinue.height / 2.0f);
  endLevelText[4].setPosition(static_cast<float>(graphicManager->GetWindow()->getSize().x) / 2.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 150.0f);
}

Level::~Level()
{
  ClearAll();
}

void Level::Update(float deltaTime)
{
  entities->Update(deltaTime, playerOne);

  list<Item *>::iterator itItem;
  for (itItem = items.begin(); itItem != items.end(); itItem++)
    if ((*itItem)->GetCaught() && (*itItem)->GetStair())
      (*itItem)->SetPosition(sf::Vector2f(graphicManager->GetView()->getCenter().x + (graphicManager->GetView()->getSize().x / 2.0f) - (*itItem)->GetHalfSize().x - 20.0f, graphicManager->GetView()->getCenter().y - (graphicManager->GetView()->getSize().y / 2.0f) + (*itItem)->GetHalfSize().y + 20.0f));

  scoreText[0].setPosition(graphicManager->GetView()->getCenter().x - (graphicManager->GetView()->getSize().x / 2.0f) + 30.0f, 40.0f);
  scoreText[1].setPosition(graphicManager->GetView()->getCenter().x - (graphicManager->GetView()->getSize().x / 2.0f) + 215.0f, 40.0f);
  scoreText[1].setString(to_string(score));

  heartsText[0].setPosition(graphicManager->GetView()->getCenter().x - 50.0f, 40.0f);
  heartsText[1].setPosition(graphicManager->GetView()->getCenter().x + 50.0f, 40.0f);
  heartsText[0].setString(to_string(hearts));
}

void Level::CheckCollison()
{
  colliderManager->CheckEntitiesCollison(entities, obstacles, characters);
  colliderManager->CheckPlayerOnHead(score, characters, playerOne, NULL);
  colliderManager->CheckItemCollision(items, playerOne, NULL);
}

void Level::SetViewCenter()
{
  // code to set the view to not extrapolate the level limits borders
  sf::Vector2f viewCenter = playerOne->GetPosition();

  // set in Y
  if (viewCenter.y + (view->getSize().y / 2.0f) >= static_cast<float>(window->getSize().y))
    viewCenter.y = static_cast<float>(window->getSize().y) - (view->getSize().y / 2.0f);
  if (viewCenter.y - (view->getSize().y / 2.0f) <= 0.0f)
    viewCenter.y = (view->getSize().y / 2.0f);

  // set in X
  if (viewCenter.x - (view->getSize().x / 2.0f) <= 0.0f)
    viewCenter.x = view->getSize().x / 2.0f;
  if (viewCenter.x + (view->getSize().x / 2.0f) >= sizeX)
    viewCenter.x = sizeX - (view->getSize().x / 2.0f);

  view->setCenter(viewCenter);
  window->setView(*view);
}

void Level::SetEndLevel(sf::Event event)
{
  endLevelBackground.setPosition(graphicManager->GetView()->getCenter());

  endLevelText[0].setPosition(graphicManager->GetView()->getCenter().x, 50.0f);
  endLevelText[1].setPosition(graphicManager->GetView()->getCenter().x, 100.0f);
  endLevelText[2].setPosition(graphicManager->GetView()->getCenter().x - 300.0f, graphicManager->GetView()->getCenter().y);
  endLevelText[3].setPosition(graphicManager->GetView()->getCenter().x + 100.0f, graphicManager->GetView()->getCenter().y);
  endLevelText[4].setPosition(graphicManager->GetView()->getCenter().x, graphicManager->GetView()->getCenter().y + 275.0f);

  endLevelText[1].setString(finalPhrase);
  endLevelText[3].setString(to_string(score));

  if (event.type == sf::Event::TextEntered)
    if (event.text.unicode == '\b' && name.size() > 0)
      name.pop_back();
    else if (event.text.unicode > 33 && event.text.unicode < 126)
      name += event.text.unicode;

  endLevelText[2].setString(name);
}

int Level::SetContinueLevel(sf::Event event, Ranking *ranking)
{
  if (event.key.code == sf::Keyboard::Down)
  {
    endLevelText[2].setFillColor(sf::Color::White);
    endLevelText[4].setFillColor(sf::Color::Red);
    return -1;
  }

  if (event.key.code == sf::Keyboard::Up)
  {
    endLevelText[2].setFillColor(sf::Color::Red);
    endLevelText[4].setFillColor(sf::Color::White);
    return -1;
  }

  if (event.key.code == sf::Keyboard::Return && endLevelText[4].getFillColor() == sf::Color::Red)
  {
    ranking->SetRank(name, score);
    return nextLevel;
  }

  return -1;
}

void Level::Draw(sf::RenderWindow &window)
{
  list<Item *>::iterator itItem;
  for (itItem = items.begin(); itItem != items.end(); itItem++)
    if ((*itItem)->GetCaught() && (*itItem)->GetDoor())
      endLevel = true;

  if (!endLevel)
  {
    window.draw(background);
    window.draw(healthBox);
    window.draw(scoreText[0]);
    window.draw(scoreText[1]);
    window.draw(heartsText[0]);
    window.draw(heartsText[1]);
    entities->DrawEntities(window);
  }
  else
  {
    window.draw(endLevelBackground);
    for (int i = 0; i < 5; i++)
      window.draw(endLevelText[i]);
  }
}

void Level::ClearAll()
{
  entities->DeleteEntities();
}
