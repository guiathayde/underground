#include "LevelSewer.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "WelderEnemy.h"
#include "HollowHatEnemy.h"
#include "Item.h"
#include "Spike.h"
#include "ChildPlayerTwo.h"
#include "ChildPlayerOne.h"
#include "TrashMonster.h"
#include "WallPlatform.h"
#include "AirPlatform.h"
#include "BasePlatform.h"
#include "TrapPlatform.h"
#include "Stair.h"
#include "Door.h"

LevelSewer::LevelSewer(GraphicManager *graphicManager, ColliderManager *manageCollider, bool isCoop) : Level(graphicManager, manageCollider)
{

  this->isCoop = isCoop;

  nameLevel = "Sewer";
  finalPhrase = "You escaped from the sewer!";
  sizeX = 5000.0f;
  enemiesNum = 2;
  nextLevel = 2;

  backgroundTexture = graphicManager->GetTexture("levelOne");
  sf::Vector2u windowSize = graphicManager->GetWindow()->getSize();
  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture->getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(backgroundTexture);

  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);

  BasePlatform *basePlatform = new BasePlatform(graphicManager, sf::Vector2f(sizeX, 200.0f), sf::Vector2f(basePlatformPosition.x + 2500.0f, basePlatformPosition.y + 100.0f));
  BasePlatform *limitBorderYLeft = new BasePlatform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y / 2.0f));
  BasePlatform *limitBorderYRight = new BasePlatform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(sizeX, basePlatformPosition.y / 2.0f));

  entities->InsertDynamicEntity(basePlatform);
  obstacles.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  obstacles.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  obstacles.push_back(limitBorderYRight);
}

LevelSewer::~LevelSewer()
{
}

void LevelSewer::InitializeCharacters()
{
  initialPosition.x = 31.0f;
  initialPosition.y = static_cast<float>(graphicManager->GetWindow()->getSize().y) - 31.0f;
  ChildPlayerOne *playerOne = new ChildPlayerOne(graphicManager, sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 31.0f));
  characters.push_back(playerOne);
  entities->InsertDynamicEntity(playerOne);
  SetPlayerOne(playerOne);

  if (isCoop)
  {

    ChildPlayerTwo *playerTwo = new ChildPlayerTwo(graphicManager, sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 21.0f));
    characters.push_back(playerTwo);
    entities->InsertDynamicEntity(playerTwo);
    SetPlayerTwo(playerTwo);
  }

  for (int i = 0; i < enemiesNum; i++)
  {
    sf::Vector2f enemyPosistion;
    enemyPosistion.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion.y = 0.0f;

    sf::Vector2f enemyPosistion1;
    enemyPosistion1.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion1.y = 0.0f;

    sf::Vector2f enemyPosistion2;
    enemyPosistion2.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion2.y = 0.0f;

    WelderEnemy *aux1 = NULL;
    HollowHatEnemy *aux2 = NULL;

    aux1 = new WelderEnemy(graphicManager, enemyPosistion2, entities);
    characters.push_back(aux1);
    entities->InsertDynamicEntity(aux1);
    /*
      Enemy *boss = new TrashMonster(graphicManager, enemyPosistion);
      characters.push_back(boss);
      entities->InsertDynamicEntity(boss);
    */
      aux2 = new HollowHatEnemy(graphicManager, enemyPosistion1);
      characters.push_back(aux2);
      entities->InsertDynamicEntity(aux2);
    
  }
}

void LevelSewer::Initialize()
{
  /* --------------------------------------------------------- SetUp base obstacles ------------------------------------------------------ */

  AirPlatform *airPlatformBase = new AirPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  TrapPlatform *trapPlatformBase = new TrapPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  Spike *spikesBase = new Spike(graphicManager, sf::Vector2f(0.0f, 0.0f));
  WallPlatform *wallPlatformBase = new WallPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp Spikes --------------------------------------------------------- */

  Spike *spikesFirst = new Spike(graphicManager, sf::Vector2f(300.0f, basePlatformPosition.y - (static_cast<float>(graphicManager->GetTexture("spikes")->getSize().y) / 2.0f)));
  entities->InsertDynamicEntity(spikesFirst);
  obstacles.push_back(spikesFirst);

  Spike *spikesPrevious = spikesFirst;
  Spike *spikesLast = NULL;
  for (int i = 0; i < 8; i++)
  {
    spikesLast = new Spike(graphicManager, sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - (static_cast<float>(graphicManager->GetTexture("spikes")->getSize().y) / 2.0f)));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    obstacles.push_back(spikesLast);
  }

  /* --------------------------------------------------------- SetUp First Air Platform --------------------------------------------------------- */

  AirPlatform *airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(710.0f, basePlatformPosition.y - 50.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  AirPlatform *airPlatformPrevious = airPlatformFirst;
  AirPlatform *airPlatformLast = NULL;
  for (int i = 0; i < 6; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 50.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  /* --------------------------------------------------------- SetUp Platform to Stair --------------------------------------------------------- */

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(2078.0f, basePlatformPosition.y - 150.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 6; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 150.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  WallPlatform *wallPlatformFirst = new WallPlatform(graphicManager, sf::Vector2f(airPlatformLast->GetPosition().x + airPlatformBase->GetHalfSize().x - wallPlatformBase->GetHalfSize().x, airPlatformLast->GetPosition().y - airPlatformBase->GetHalfSize().y - wallPlatformBase->GetHalfSize().y));
  entities->InsertDynamicEntity(wallPlatformFirst);
  obstacles.push_back(wallPlatformFirst);

  WallPlatform *wallPlatformPrevious = wallPlatformFirst;
  WallPlatform *wallPlatformLast = NULL;
  for (int i = 0; i < 3; i++)
  {
    wallPlatformLast = new WallPlatform(graphicManager, sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y - wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    obstacles.push_back(wallPlatformLast);
  }

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(wallPlatformLast->GetPosition().x + wallPlatformBase->GetHalfSize().x + airPlatformBase->GetHalfSize().x, basePlatformPosition.y - 332.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 6; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 332.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  Stair *stair = new Stair(graphicManager, sf::Vector2f(2581.5f, basePlatformPosition.y - 372.0f), 1);
  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  // --------------------------------------------------------- SetUp Spikes and AirPlatform ---------------------------------------------------------

  spikesFirst = new Spike(graphicManager, sf::Vector2f(2604.5f, basePlatformPosition.y - (static_cast<float>(graphicManager->GetTexture("spikes")->getSize().y) / 2.0f)));
  entities->InsertDynamicEntity(spikesFirst);
  obstacles.push_back(spikesFirst);

  spikesPrevious = spikesFirst;
  spikesLast = NULL;
  for (int i = 0; i < 11; i++)
  {
    spikesLast = new Spike(graphicManager, sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    obstacles.push_back(spikesLast);
  }

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(3180.5f, basePlatformPosition.y - 30.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 6; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 30.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  //----------------------------------------------------------- SetUp Exit Platform --------------------------------------------------------- */

  wallPlatformFirst = new WallPlatform(graphicManager, sf::Vector2f(4164.0f, basePlatformPosition.y - 23.0f));
  entities->InsertDynamicEntity(wallPlatformFirst);
  obstacles.push_back(wallPlatformFirst);

  wallPlatformPrevious = wallPlatformFirst;
  wallPlatformLast = NULL;
  for (int i = 0; i < 3; i++)
  {
    wallPlatformLast = new WallPlatform(graphicManager, sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y - wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    obstacles.push_back(wallPlatformLast);
  }

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(4195.5f, basePlatformPosition.y - 177.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 4; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 177.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  wallPlatformFirst = new WallPlatform(graphicManager, sf::Vector2f(4394.0f, basePlatformPosition.y - 207.0f));
  entities->InsertDynamicEntity(wallPlatformFirst);
  obstacles.push_back(wallPlatformFirst);

  wallPlatformPrevious = wallPlatformFirst;
  wallPlatformLast = NULL;
  for (int i = 0; i < 3; i++)
  {
    wallPlatformLast = new WallPlatform(graphicManager, sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y - wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    obstacles.push_back(wallPlatformLast);
  }

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(4425.0f, basePlatformPosition.y - 361.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 12; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 361.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  Door *door = new Door(graphicManager, sf::Vector2f(4931.0f, basePlatformPosition.y - 424.5f));
  entities->InsertDynamicEntity(door);
  items.push_back(door);

  InitializeCharacters();
}