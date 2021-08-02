#include "Level.h"

Level::Level(int level, sf::Texture backgroundTexture, sf::View *view, float sizeX)
{
  this->level = level;
  this->sizeX = sizeX;
  this->backgroundTexture = backgroundTexture;
  this->view = view;
}

Level::~Level()
{
}

void Level::Initialize(int enemiesNum, sf::RenderWindow &window)
{
  sf::Vector2u windowSize = window.getSize();

  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture.getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(&backgroundTexture);

  characters.InitializeCharacters(enemiesNum);

  playerOne = static_cast<Player *>(characters.GetPlayer());

  static sf::Texture plataformTexture;
  if (!plataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    printf("Error loading platform texture\n");

  sf::Vector2f basePlatformPosition;
  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);
  Platform *auxPlatform = new Platform(&plataformTexture, sf::Vector2f(5000.0f, 5.0f), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y + 2.5f));
  Platform *auxPlatform2 = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y));
  Platform *auxPlatform3 = new Platform(&plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(2500.0f, basePlatformPosition.y));

  this->platforms.push_back(auxPlatform);
  this->platforms.push_back(auxPlatform2);
  this->platforms.push_back(auxPlatform3);

  basePlatformPosition.y -= 36.0f;
  basePlatformPosition.x += 31.0f;
  playerOne->SetPosition(basePlatformPosition);
}

void Level::CheckCollison()
{
  characters.CheckCharactersCollision(platforms);
}

void Level::Update(float deltaTime)
{
  characters.UpdateCharacter(deltaTime);

  float backgroundX = deltaTime * GetPlayer()->GetVelocityX() * -0.15f;

  if (background.getPosition().x + backgroundX > 0.0f && background.getPosition().x + background.getSize().x < GetSizeX())
    background.move(deltaTime * GetPlayer()->GetVelocityX() * -0.05f, 0.0f);
}

void Level::Draw(sf::RenderWindow &window)
{
  std::list<Platform *>::iterator itPlatform;

  window.draw(background);
  characters.DrawCharacters(window);
  for (itPlatform = platforms.begin(); itPlatform != platforms.end(); ++itPlatform)
    (*itPlatform)->Draw(window);
}