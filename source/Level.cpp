#include "stdfx.h"
#include "Level.h"
#include "Player.h"
#include "Obstacle.h"
#include "GraphicManager.h"
#include "ColliderManager.h"
#include "Item.h"

Level::Level(GraphicManager *graphicManager, ColliderManager *colliderManager) : Entity(graphicManager), colliderManager(colliderManager)
{
  n_entities = 0;
  score = 0;

  sizeX = 5000.0f;

  this->graphicManager = graphicManager;

  view = graphicManager->GetView();
  window = graphicManager->GetWindow();

  entities = new DynamicEntityList();

  if (!font.loadFromFile("assets/fonts/DarkMage.ttf"))
    cerr << "Error loading item DarkMage font!" << endl;

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
      (*itItem)->SetPosition(sf::Vector2f(
          graphicManager->GetView()->getCenter().x + (graphicManager->GetView()->getSize().x / 2.0f) - (*itItem)->GetHalfSize().x - 20.0f,
          graphicManager->GetView()->getCenter().y - (graphicManager->GetView()->getSize().y / 2.0f) + (*itItem)->GetHalfSize().y + 20.0f));

  string scoreUpdated = to_string(score);
  scoreText[0].setPosition(graphicManager->GetView()->getCenter().x - (graphicManager->GetView()->getSize().x / 2.0f) + 30.0f, 40.0f);
  scoreText[1].setPosition(graphicManager->GetView()->getCenter().x - (graphicManager->GetView()->getSize().x / 2.0f) + 215.0f, 40.0f);
  scoreText[1].setString(scoreUpdated);
}

void Level::CheckCollison()
{
  colliderManager->CheckEntitiesCollison(entities, platforms, characters);
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

void Level::Draw(sf::RenderWindow &window)
{
  window.draw(background);
  window.draw(scoreText[0]);
  window.draw(scoreText[1]);
  entities->DrawEntities(window);
}

void Level::ClearAll()
{
  entities->DeleteEntities();
}
