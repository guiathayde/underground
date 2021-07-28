#include <iostream>
using namespace std;

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
  std::list<Enemy>::iterator itEnemies;
  static sf::Texture enemyTexture;
  if (!enemyTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    cerr << "Error loading enemy texture" << endl;

  for (int i = 0; i < enemiesNum; i++)
  {

    Enemy *aux = new Enemy(&enemyTexture, sf::Vector2u(6, 2), sf::Vector2f(i * 100.0f, 200.0f), 0.3f, 100.0f, 100.0f, 3, true);
    this->enemies.push_back(aux);
  }

  static sf::Texture playerTexture;
  if (!playerTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png"))
    cerr << "Error loading player texture" << endl;
  Player *p = new Player(&playerTexture, sf::Vector2u(4, 4), sf::Vector2f(-200.0f, 200.0f), 0.30f, 200.0f, 200.0f, 300, true, true);

  playerOne = p;

  static sf::Texture plataformTexture;

  if (!plataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    cerr << "Error loading platform texture" << endl;
  Platform *auxPlatform = new Platform(&plataformTexture, sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(100.0f, 600.0f));
  this->platforms.push_back(auxPlatform);
}

void Level::CheckCollison()
{
  sf::Vector2f direction;
  std::list<Platform *>::iterator itPlatform;
  std::list<Enemy *>::iterator itEnemy;

  for (itPlatform = platforms.begin(); itPlatform != platforms.end(); itPlatform++)
  {
    if ((*itPlatform)->GetCollider().CheckCollision(playerOne->GetCollider(), direction, 1.0f))
      playerOne->OnCollision(direction);

    for (itEnemy = enemies.begin(); itEnemy != enemies.end(); itEnemy++)
      if ((*itPlatform)->GetCollider().CheckCollision((*itEnemy)->GetCollider(), direction, 1.0f))
        (*itEnemy)->OnCollision(direction);
  }

  for (itEnemy = enemies.begin(); itEnemy != enemies.end(); itEnemy++)
    if (playerOne->GetCollider().CheckCollision((*itEnemy)->GetCollider(), direction, 1.0f))
      playerOne->GetDamage();
}

void Level::Draw(sf::RenderWindow &window)
{
  std::list<Platform *>::iterator itPlatform;
  std::list<Enemy *>::iterator itEnemy;

  //desenha o jogador
  if (playerOne->GetIsAlive())
  {
    playerOne->Draw(window);

    //desenha os inimigos a partir da lista
    for (itEnemy = enemies.begin(); itEnemy != enemies.end(); ++itEnemy)
    {
      if ((*itEnemy)->GetIsAlive())
      {
        (*itEnemy)->Draw(window);
      }

      for (itPlatform = platforms.begin(); itPlatform != platforms.end(); ++itPlatform)
        (*itPlatform)->Draw(window);
    }
  }
}

void Level::Update(float deltaTime)
{
  std::list<Enemy *>::iterator itEnemy;

  if (playerOne->GetIsAlive())
  {
    playerOne->Update(deltaTime);
    for (itEnemy = enemies.begin(); itEnemy != enemies.end(); itEnemy++)
      (*itEnemy)->Update(deltaTime, *playerOne);
  }
}