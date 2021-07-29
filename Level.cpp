#include "Level.h"

Level::Level(int level, sf::Texture backgroundTexture)
{
  this->level = level;
  this->backgroundTexture = backgroundTexture;
}

Level::~Level()
{
}

void Level::Initialize(int enemiesNum)
{
  //Testando lista Template
  characters.InitializeCharacters(enemiesNum);
  
  std::list<Enemy>::iterator itEnemies;
  static sf::Texture enemyTexture;
  if (enemyTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    printf("Carregou inimigo\n");

  for (int i = 0; i < enemiesNum; i++)
  {

    Enemy *aux = NULL;
    aux =  new Enemy(&enemyTexture, sf::Vector2u(6, 2), sf::Vector2f(i*100.0f, 200.0f), 0.3f, 100.0f, 100.0f, 3, true,false);
    this->enemies.push_back(aux);
    
  
  }

  static sf::Texture playerTexture;
  if (playerTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png"))
   printf("Carregou player\n");
  static sf::Texture plataformTexture;

  if (plataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    printf("Carregou plataforma\n");
  Platform *auxPlatform = new Platform(&plataformTexture, sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(100.0f, 600.0f));
  this->platforms.push_back(auxPlatform);
}

void Level::CheckCollison()
{
  
  
  characters.CheckCharactersCollision(platforms);
  


}

void Level::Draw(sf::RenderWindow &window)
{
  
  //cout <<"entrou"<<endl;
  std::list<Platform *>::iterator itPlatform;

  //desenha o jogador
  
  
    characters.DrawCharaceters(window);
    //cout << "Saiu do Drawn"<<endl;
    for (itPlatform = platforms.begin(); itPlatform != platforms.end(); ++itPlatform)
      (*itPlatform)->Draw(window);
  
}

void Level::Update(float deltaTime)
{
  //cout << "Update" <<endl;
  characters.UpdateCharacter(deltaTime);
  //cout <<"Update2" << endl;
} 