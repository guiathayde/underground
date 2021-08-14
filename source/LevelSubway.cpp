#include "LevelSubway.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "WelderEnemy.h"
#include "HollowHatEnemy.h"
#include "Item.h"
#include "Spike.h"
#include "ChildPlayer.h"
#include "TrashMonster.h"
#include "WallPlatform.h"
#include "AirPlatform.h"
#include "BasePlatform.h"
#include "TrapPlatform.h"
#include "Stair.h"
#include "Door.h"

LevelSubway::LevelSubway(GraphicManager *graphicManager, ColliderManager *graphicCollider) : Level(graphicManager, graphicCollider)
{
  nameLevel = "Subway";
  sizeX = 5600.0f;
  enemiesNum = 3;
  nextLevel = 3;
  backgroundTexture = graphicManager->GetTexture("levelTwo");
}

LevelSubway::~LevelSubway()
{
}

void LevelSubway::InitializeCharacters()
{
  ChildPlayer *playerOne = new ChildPlayer(graphicManager, sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 21.0f));
  characters.push_back(playerOne);
  entities->InsertDynamicEntity(playerOne);
  SetPlayerOne(playerOne);

  for (int i = 0; i < enemiesNum; i++)
  {
    sf::Vector2f enemyPosistion;
    enemyPosistion.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion.y = 0.0f;

    sf::Vector2f enemyPosistion1;
    enemyPosistion1.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion1.y = 0.0f;

    sf::Vector2f enemyPosistion2;
    enemyPosistion1.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion1.y = 0.0f;

    Enemy *boss = new TrashMonster(graphicManager, enemyPosistion2);
    characters.push_back(boss);
    entities->InsertDynamicEntity(boss);

    Enemy *aux = new HollowHatEnemy(graphicManager, enemyPosistion);
    characters.push_back(aux);
    entities->InsertDynamicEntity(aux);

    Enemy *aux1 = new WelderEnemy(graphicManager, enemyPosistion1, entities);
    characters.push_back(aux1);
    entities->InsertDynamicEntity(aux1);
  }
}

void LevelSubway::Initialize()
{
  /* --------------------------------------------------------- SetUp base obstacles ------------------------------------------------------ */

  cout << "inicializou o level subway" <<endl;

  AirPlatform *airPlatformBase = new AirPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  cout << "news feitos1"<<endl;

  TrapPlatform *trapPlatformBase = new TrapPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  cout << "news feitos2"<<endl;

  Spike *spikesBase = new Spike(graphicManager, sf::Vector2f(0.0f, 0.0f));
    cout << "news feitos3"<<endl;

  WallPlatform *wallPlatformBase = new WallPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  cout << "news feitos4"<<endl;

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp base platform and limits -------------------------------------------- */
  sf::Vector2u windowSize = graphicManager->GetWindow()->getSize();

  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture->getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(backgroundTexture);

  sf::Vector2f basePlatformPosition;
  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);

  BasePlatform *basePlatform = new BasePlatform(graphicManager, sf::Vector2f(sizeX, 200.0f), sf::Vector2f(basePlatformPosition.x + (sizeX / 2.0f), basePlatformPosition.y + 100.0f));
  BasePlatform *limitBorderYLeft = new BasePlatform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(basePlatformPosition.x - 2.5f, basePlatformPosition.y / 2.0f));
  BasePlatform *limitBorderYRight = new BasePlatform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(sizeX + 2.5f, basePlatformPosition.y / 2.0f));

  cout << "entrou do insere" <<endl;
  entities->InsertDynamicEntity(basePlatform);
  obstacles.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  obstacles.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  obstacles.push_back(limitBorderYRight);
  cout << "saiu do insere" <<endl;
  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp way to stairs ------------------------------------------------------- */
  
  AirPlatform *airPlatform1 = new AirPlatform(graphicManager, sf::Vector2f(airPlatformBase->GetHalfSize().x , basePlatformPosition.y - 150.0f));
  AirPlatform *airPlatform2 = new AirPlatform(graphicManager, sf::Vector2f(airPlatformBase->GetHalfSize().x * 6.0f, basePlatformPosition.y - 300.0f));
  AirPlatform *airPlatform3 = new AirPlatform(graphicManager, sf::Vector2f(airPlatformBase->GetHalfSize().x, basePlatformPosition.y - 450.0f));
  TrapPlatform *trapPlatform1 = new TrapPlatform(graphicManager, sf::Vector2f(trapPlatformBase->GetHalfSize().x * 6.0f, basePlatformPosition.y - 600.0f));
  AirPlatform *airPlatform4 = new AirPlatform(graphicManager, sf::Vector2f(trapPlatformBase->GetHalfSize().x * 30.0f, basePlatformPosition.y - 600.0f));

  //cout << "stair deu new" <<endl;
  Stair *stair = new Stair(graphicManager, sf::Vector2f((trapPlatformBase->GetHalfSize().x / 2.0f) * 30.0f, basePlatformPosition.y - 600.0f - airPlatform4->GetHalfSize().y - (graphicManager->GetTexture("stair2")->getSize().y / 2.0f)),2);
  //cout << "stair da deu new" <<endl;
  stair->SetStair(true);
  entities->InsertDynamicEntity(airPlatform1);
  obstacles.push_back(airPlatform1);
  entities->InsertDynamicEntity(airPlatform2);
  obstacles.push_back(airPlatform2);
  entities->InsertDynamicEntity(airPlatform3);
  obstacles.push_back(airPlatform3);
  entities->InsertDynamicEntity(trapPlatform1);
  obstacles.push_back(trapPlatform1);
  entities->InsertDynamicEntity(airPlatform4);
  obstacles.push_back(airPlatform4);

  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp First Spikes --------------------------------------------------------- */

  Spike *spikesFirst = new Spike(graphicManager, sf::Vector2f(airPlatform2->GetPosition().x + airPlatform2->GetHalfSize().x + (graphicManager->GetTexture("spikes")->getSize().x / 2.0f), basePlatformPosition.y - spikesBase->GetHalfSize().y));
  entities->InsertDynamicEntity(spikesFirst);
  obstacles.push_back(spikesFirst);

  Spike *spikesPrevious = spikesFirst;
  Spike *spikesLast = NULL;
  for (int i = 0; i < 12; i++)
  {
    spikesLast = new Spike(graphicManager, sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    obstacles.push_back(spikesLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------ SetUp Ladder + Second Spikes + Air Platform ----------------------------------------------- */

  AirPlatform *airPlatform5 = new AirPlatform(graphicManager, sf::Vector2f(spikesLast->GetPosition().x + spikesLast->GetSize().x + 1800.0f, basePlatformPosition.y - 150.0f));
  TrapPlatform *trapPlatform2 = new TrapPlatform(graphicManager, sf::Vector2f(airPlatform5->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 300.0f));
  AirPlatform *airPlatform6 = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform2->GetPosition().x + (trapPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 450.0f));
  TrapPlatform *trapPlatform3 = new TrapPlatform(graphicManager, sf::Vector2f(airPlatform6->GetPosition().x + (trapPlatformBase->GetSize().x * 5.0f), basePlatformPosition.y - 300.0f));
  AirPlatform *airPlatform7 = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform3->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 450.0f));

  entities->InsertDynamicEntity(airPlatform5);
  obstacles.push_back(airPlatform5);
  entities->InsertDynamicEntity(trapPlatform2);
  obstacles.push_back(trapPlatform2);
  entities->InsertDynamicEntity(airPlatform6);
  obstacles.push_back(airPlatform6);
  entities->InsertDynamicEntity(airPlatform7);
  obstacles.push_back(airPlatform7);
  entities->InsertDynamicEntity(trapPlatform3);
  obstacles.push_back(trapPlatform3);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  spikesFirst = new Spike(graphicManager, sf::Vector2f(spikesLast->GetPosition().x + spikesLast->GetSize().x + 1800.0f, basePlatformPosition.y - spikesBase->GetHalfSize().y));
  entities->InsertDynamicEntity(spikesFirst);
  obstacles.push_back(spikesFirst);

  spikesPrevious = spikesFirst;
  spikesLast = NULL;
  for (int i = 0; i < 44; i++)
  {
    spikesLast = new Spike(graphicManager, sf::Vector2f(spikesPrevious->GetPosition().x + spikesPrevious->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    obstacles.push_back(spikesLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  AirPlatform *airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform3->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f) + 500.0f, basePlatformPosition.y - 450.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  AirPlatform *airPlatformPrevious = airPlatformFirst;
  AirPlatform *airPlatformLast = NULL;
  for (int i = 0; i < 15; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, basePlatformPosition.y - 450.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------ SetUp Air Platform down + Leader to exit + Exit ------------------------------------------- */

  AirPlatform *airPlatformLastBridge = airPlatformLast;

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(airPlatformLast->GetPosition().x + 500.0f, basePlatformPosition.y - 100.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  for (int i = 0; i < 1; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, basePlatformPosition.y - 100.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  AirPlatform *airPlatform8 = new AirPlatform(graphicManager, sf::Vector2f(sizeX - airPlatformBase->GetHalfSize().x, basePlatformPosition.y - 250.0f));
  AirPlatform *airPlatform9 = new AirPlatform(graphicManager, sf::Vector2f(airPlatform8->GetPosition().x - 100.0f, basePlatformPosition.y - 400.0f));

  entities->InsertDynamicEntity(airPlatform8);
  obstacles.push_back(airPlatform8);
  entities->InsertDynamicEntity(airPlatform9);
  obstacles.push_back(airPlatform9);

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  airPlatformFirst = new AirPlatform(graphicManager,  sf::Vector2f(airPlatformLastBridge->GetPosition().x + 200.0f, airPlatformLastBridge->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  for (int i = 0; i < 5; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager,  sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  WallPlatform *wallPlatformFirst = new WallPlatform(graphicManager, sf::Vector2f(airPlatformFirst->GetPosition().x - airPlatformBase->GetHalfSize().x + wallPlatformBase->GetHalfSize().x, airPlatformFirst->GetPosition().y - airPlatformBase->GetHalfSize().y - wallPlatformBase->GetHalfSize().y));
  entities->InsertDynamicEntity(wallPlatformFirst);
  obstacles.push_back(wallPlatformFirst);

  WallPlatform *wallPlatformPrevious = wallPlatformFirst;
  WallPlatform *wallPlatformLast = NULL;
  for (int i = 0; i < 5; i++)
  {
    wallPlatformLast = new WallPlatform(graphicManager, sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y - wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    obstacles.push_back(wallPlatformLast);
  }

  Door *door = new Door(graphicManager, sf::Vector2f(airPlatformFirst->GetPosition().x + airPlatformBase->GetHalfSize().x, wallPlatformFirst->GetPosition().y + wallPlatformBase->GetHalfSize().y - (graphicManager->GetTexture("door")->getSize().y / 2.0f)));
  door->SetDoor(true);
  entities->InsertDynamicEntity(door);
  items.push_back(door);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  delete airPlatformBase;
  delete trapPlatformBase;
  delete spikesBase;
  delete wallPlatformBase;

  InitializeCharacters();
}