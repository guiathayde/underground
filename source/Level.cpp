#include "Level.h"

Level::Level(int level, sf::Texture backgroundTexture, sf::View *view, float sizeX):entities(n_entities,true)
{
  this->sizeX = sizeX;
  this->level = level;
  this->backgroundTexture = backgroundTexture;
  this->view = view;
}

Level::~Level()
{
  ClearAll();
}

void Level::Initialize(int enemiesNum, sf::RenderWindow &window)
{
  //Testando lista Template
  
  characters.InitializeCharacters(enemiesNum,&entities);
  
  sf::Vector2u windowSize = window.getSize();

  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture.getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(&backgroundTexture);

  playerOne = static_cast<Player *>(characters.GetPlayer());

  static sf::Texture plataformTexture;
  if (!plataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    printf("Error loading platform texture\n");

  sf::Vector2f basePlatformPosition;
  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);
  
  Platform *auxPlatform = new Platform(&plataformTexture, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y + 2.5f));
  Platform *auxPlatform2 = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y));
  Platform *auxPlatform3 = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(2500.0f, basePlatformPosition.y));
  
  entities.InsertEntity(auxPlatform);
  entities.InsertEntity(auxPlatform2);
  entities.InsertEntity(auxPlatform3);

}

void Level::CheckCollison()
{
  entities.CheckEntitysCollision();

}

void Level::Draw(sf::RenderWindow &window)
{

  window.draw(background);
  entities.DrawEntitys(window); 


}

void Level::Update(float deltaTime)
{
 
  //cout << "Update" <<endl;
  characters.UpdateCharacter(deltaTime);
  //cout <<"Update2" << endl;

} 

void Level::ClearAll(){
  entities.DeleteEntitys();

}