#include "Level.h"

Level::Level(int level, sf::Texture backgroundTexture, sf::View *view, float sizeX) : entities(n_entities, true)
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
  characters.InitializeCharacters(enemiesNum, &entities);

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

  Platform *basePlatform = new Platform(&plataformTexture, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(basePlatformPosition.x + 2500.0f, basePlatformPosition.y + 50.0f));
  Platform *limitBorderYLeft = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y / 2.0f));
  Platform *limitBorderYRight = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(5000.0f, basePlatformPosition.y / 2.0f));

  entities.InsertEntity(basePlatform);
  entities.InsertEntity(limitBorderYLeft);
  entities.InsertEntity(limitBorderYRight);
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
  characters.UpdateCharacter(deltaTime);
}

void Level::ClearAll()
{
  entities.DeleteEntitys();
}