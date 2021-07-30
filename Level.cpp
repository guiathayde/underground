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
  characters.InitializeCharacters(enemiesNum);

  static sf::Texture plataformTexture;
  if (!plataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    printf("Error loading platform texture\n");

  Platform *auxPlatform = new Platform(&plataformTexture, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(0.0f, 800.0f));
  // Platform *auxPlatform2 = new Platform(&plataformTexture, sf::Vector2f(2000.0f, 200.0f), sf::Vector2f(300.0f, 400.0f));
  // Platform *auxPlatform3 = new Platform(&plataformTexture, sf::Vector2f(100.0f, 1000.0f), sf::Vector2f(200.0f, 300.0f));

  this->platforms.push_back(auxPlatform);
  // this->platforms.push_back(auxPlatform2);
  // this->platforms.push_back(auxPlatform3);
}

void Level::CheckCollison()
{
  characters.CheckCharactersCollision(platforms);
}

void Level::Draw(sf::RenderWindow &window)
{
  std::list<Platform *>::iterator itPlatform;

  characters.DrawCharacters(window);
  for (itPlatform = platforms.begin(); itPlatform != platforms.end(); ++itPlatform)
    (*itPlatform)->Draw(window);
}

void Level::Update(float deltaTime)
{
  characters.UpdateCharacter(deltaTime);
}