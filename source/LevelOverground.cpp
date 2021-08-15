#include "LevelOverground.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "WelderEnemy.h"
#include "HollowHatEnemy.h"
#include "Item.h"
#include "Spike.h"
#include "ChildPlayerOne.h"
#include "TrashMonster.h"
#include "WallPlatform.h"
#include "AirPlatform.h"
#include "BasePlatform.h"
#include "TrapPlatform.h"
#include "Stair.h"
#include "Door.h"

LevelOverground::LevelOverground(GraphicManager *graphicManager, ColliderManager *manageCollider) : Level(graphicManager, manageCollider)
{
  nameLevel = "Overground";
  sizeX = 5400.0f;
  enemiesNum = 3;
  nextLevel = 0;

  backgroundTexture = graphicManager->GetTexture("levelThree");
}

LevelOverground::~LevelOverground()
{
}

void LevelOverground::InitializeCharacters(DynamicEntityList* entities)
{
  ChildPlayerOne *playerOne = new ChildPlayerOne(graphicManager, sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 21.0f));
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

    Enemy *boss = new TrashMonster(graphicManager, enemyPosistion1);
    characters.push_back(boss);
    entities->InsertDynamicEntity(boss);

    Enemy *aux = new HollowHatEnemy(graphicManager, enemyPosistion);
    characters.push_back(aux);
    entities->InsertDynamicEntity(aux);

    /*
    Enemy *aux1 = new WelderEnemy(graphicManager, enemyPosistion1,entities);
    characters.push_back(aux1);
    entities->InsertDynamicEntity(aux1);
    */
  }
}

void LevelOverground::Initialize(DynamicEntityList* entities)
{

  /* --------------------------------------------------------- SetUp base obstacles ------------------------------------------------------ */

  AirPlatform *airPlatformBase = new AirPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  TrapPlatform *trapPlatformBase = new TrapPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  Spike *spikesBase = new Spike(graphicManager, sf::Vector2f(0.0f, 0.0f));
  WallPlatform *wallPlatformBase = new WallPlatform(graphicManager, sf::Vector2f(0.0f, 0.0f));
  cout <<"71"<< endl;


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
  WallPlatform *limitBorderYLeft = new WallPlatform(graphicManager, sf::Vector2f(basePlatformPosition.x - 2.5f, basePlatformPosition.y / 2.0f));
  WallPlatform *limitBorderYRight = new WallPlatform(graphicManager, sf::Vector2f(sizeX + 2.5f, basePlatformPosition.y / 2.0f));

  entities->InsertDynamicEntity(basePlatform);
  obstacles.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  obstacles.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  obstacles.push_back(limitBorderYRight);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp spikes on floor ------------------------------------------------------- */

  Spike *spikesFirst = new Spike(graphicManager, sf::Vector2f(spikesBase->GetHalfSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
  entities->InsertDynamicEntity(spikesFirst);
  obstacles.push_back(spikesFirst);

  cout <<"106"<< endl;

  Spike *spikesPrevious = spikesFirst;
  Spike *spikesLast = NULL;
  for (int i = 0; i < 84; i++)
  {
    spikesLast = new Spike(graphicManager, sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    obstacles.push_back(spikesLast);
  }

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------------ SetUp 2Traps + Air platform + 1Trap ------------------------------------------------ */

  TrapPlatform *trapPlatform1 = new TrapPlatform(graphicManager, sf::Vector2f(trapPlatformBase->GetHalfSize().x, basePlatformPosition.y - 150.0f));
  TrapPlatform *trapPlatform2 = new TrapPlatform(graphicManager, sf::Vector2f(trapPlatform1->GetPosition().x + trapPlatformBase->GetSize().x, basePlatformPosition.y - 150.0f));


  entities->InsertDynamicEntity(trapPlatform1);
  obstacles.push_back(trapPlatform1);
  entities->InsertDynamicEntity(trapPlatform2);
  obstacles.push_back(trapPlatform2);

  AirPlatform *airPlatform1 = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform2->GetPosition().x + 600.0f, basePlatformPosition.y - 150.0f));
  entities->InsertDynamicEntity(airPlatform1);
  obstacles.push_back(airPlatform1);

  AirPlatform *airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(airPlatform1->GetPosition().x + 600.0f, basePlatformPosition.y - 150.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  AirPlatform *airPlatformPrevious = airPlatformFirst;
  AirPlatform *airPlatformLast = NULL;
  for (int i = 0; i < 12; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 150.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  TrapPlatform *trapPlatform3 = new TrapPlatform(graphicManager, sf::Vector2f(airPlatformLast->GetPosition().x + 400.0f, basePlatformPosition.y - 300.0f));
  entities->InsertDynamicEntity(trapPlatform3);
  obstacles.push_back(trapPlatform3);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* -------------------------------------------------- SetUp Part of Stair --------------------------------------------------------------- */

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform3->GetPosition().x + 600.0f, basePlatformPosition.y - 300.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 22; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 300.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  WallPlatform *wallPlatformFirst = new WallPlatform(graphicManager, sf::Vector2f(airPlatformFirst->GetPosition().x - airPlatformBase->GetHalfSize().x + wallPlatformBase->GetHalfSize().x, basePlatformPosition.y - 300.0f + airPlatformBase->GetHalfSize().y - wallPlatformBase->GetHalfSize().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  WallPlatform *wallPlatformPrevious = wallPlatformFirst;
  WallPlatform *wallPlatformLast = NULL;
  for (int i = 0; i < 5; i++)
  {
    wallPlatformLast = new WallPlatform(graphicManager, sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y + wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    obstacles.push_back(wallPlatformLast);
  }

  TrapPlatform *trapPlatform4 = new TrapPlatform(graphicManager,  sf::Vector2f(airPlatformLast->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - spikesBase->GetSize().y - 20.0f));
  entities->InsertDynamicEntity(trapPlatform4);
  obstacles.push_back(trapPlatform4);

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform4->GetPosition().x - 150.0f, trapPlatform4->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 10; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x - airPlatformBase->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  TrapPlatform *trapPlatform5 = new TrapPlatform(graphicManager, sf::Vector2f(wallPlatformLast->GetPosition().x + wallPlatformBase->GetHalfSize().x + trapPlatformBase->GetHalfSize().x + 10.0f, airPlatformLast->GetPosition().y));
  entities->InsertDynamicEntity(trapPlatform5);
  obstacles.push_back(trapPlatform5);
  cout << "linha 203" << endl;
  Stair *stair = new Stair(graphicManager, sf::Vector2f(trapPlatform5->GetPosition().x, trapPlatform5->GetPosition().y - trapPlatformBase->GetHalfSize().y - (graphicManager->GetTexture("stair3")->getSize().y / 2.0f)),3);
  stair->SetStair(true);
  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* -------------------------------------------------------- SetUp Exit ------------------------------------------------------------------ */

  airPlatformFirst = new AirPlatform(graphicManager, sf::Vector2f(trapPlatform4->GetPosition().x + 600.0f, trapPlatform4->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  obstacles.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 20; i++)
  {
    airPlatformLast = new AirPlatform(graphicManager, sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    obstacles.push_back(airPlatformLast);
  }

  Door *door = new Door(graphicManager,  sf::Vector2f(airPlatformLast->GetPosition().x - (2 * airPlatformBase->GetSize().x), airPlatformLast->GetPosition().y - airPlatformBase->GetHalfSize().y - (graphicManager->GetTexture("door")->getSize().y / 2.0f)));
  door->SetDoor(true);
  entities->InsertDynamicEntity(door);
  items.push_back(door);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  delete airPlatformBase;
  delete trapPlatformBase;
  delete spikesBase;
  delete wallPlatformBase;

  InitializeCharacters(entities);
}