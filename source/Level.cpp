#include "Level.h"

Level::Level(int level, sf::Texture backgroundTexture):
entities(n_entities,true)
{
  
  this->level = level;
  this->backgroundTexture = backgroundTexture;
}

Level::~Level()
{
  ClearAll();
}

void Level::Initialize(int enemiesNum)
{
  //Testando lista Template
  cout << "Não entrou" <<endl;
  characters.InitializeCharacters(enemiesNum,&entities);
  
  if (platformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    printf("Carregou plataforma\n");

  Platform *auxPlatform = NULL;
  auxPlatform = new Platform(&platformTexture, sf::Vector2f(5000.0f, 600.0f), sf::Vector2f(1000.0f, 1000.0f));
  //Platform *auxPlatform2 = new Platform(&platformTexture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(600.0f, 600.0f));
  
  entities.InsertEntity(auxPlatform);
  ///entities.InsertEntity(auxPlatform2);

}

void Level::CheckCollison()
{
  entities.CheckEntitysCollision();

}

void Level::Draw(sf::RenderWindow &window)
{
  std::list<Platform*>::iterator itPlatform;

  for (itPlatform = platforms.begin(); itPlatform != platforms.end(); ++itPlatform)
    (*itPlatform)->Draw(window);

  entities.DrawEntitys(window); 


}

void Level::Update(float deltaTime)
{
 
  //cout << "Update" <<endl;
  characters.UpdateCharacter(deltaTime);
  //cout <<"Update2" << endl;

} 

void Level::ClearAll(){
    characters.DeleteCharacters();

}