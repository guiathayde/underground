#include "Level.h"
#include "Player.h"
#include "Obstacle.h"

Level::Level(GraphicManager *graphicManager, ColliderManager *colliderManager)
:Entity(graphicManager),colliderManager(colliderManager)
{
  sizeX = 5000.0f;
  
  view = graphicManager->GetView();
  window = graphicManager->GetWindow();

  entities = new DynamicEntityList();

}

Level::~Level()
{
  ClearAll();
}

void Level::Update(float deltaTime)
{
  /*list<Character *>::iterator it;
  for (it = characters.begin(); it != characters.end(); ++it){
    cout <<"daoe"<<endl;
    if(*it)
      (*it)->Update(deltaTime, playerOne);
  }*/  
  entities->Update(deltaTime,playerOne);

}

void Level::CheckCollison()
{
  colliderManager->CheckEntitiesCollison(entities, platforms, characters);
  colliderManager->CheckPlayerOnHead(characters, playerOne, NULL);
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
  entities->DrawEntities(window);
}


void Level::ClearAll()
{
  entities->DeleteEntities();
}
