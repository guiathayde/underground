#include "LevelSubway.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "Platform.h"
#include "Item.h"
#include "HollowHatEnemy.h"

LevelSubway::LevelSubway(GraphicManager *graphicManager, ColliderManager *graphicCollider) : Level(graphicManager, graphicCollider)
{
  sizeX = 5600.0f;
  enemiesNum = 6;
}

LevelSubway::~LevelSubway()
{
}

void LevelSubway::InitializeCharacters()
{
  Player *playerOne = new Player(graphicManager, sf::Vector2f(60.0f, 40.0f), sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 21.0f), sf::Vector2u(4, 4), 0.30f, 200.0f, 200.0f, 300, true, true, true);
  characters.push_back(playerOne);
  entities->InsertDynamicEntity(playerOne);
  SetPlayerOne(playerOne);

  for (int i = 0; i < enemiesNum; i++)
  {
    sf::Vector2f enemyPosistion;
    enemyPosistion.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion.y = 0.0f;

    Enemy *aux = new HollowHatEnemy(graphicManager, enemyPosistion);
    characters.push_back(aux);
    entities->InsertDynamicEntity(aux);
  }
}

void LevelSubway::Initialize()
{
  /* --------------------------------------------------------- Getting textures --------------------------------------------------------- */

  sf::Texture *backgroundTexture = graphicManager->GetTexture("levelTwo");
  sf::Texture *plataformTexture = graphicManager->GetTexture("basePlatformTexture");
  sf::Texture *airPlatformTexture = graphicManager->GetTexture("airPlatform");
  sf::Texture *trapPlatformTexture = graphicManager->GetTexture("trapPlatform");
  sf::Texture *spikesTexture = graphicManager->GetTexture("spikes");
  sf::Texture *stairTexture = graphicManager->GetTexture("stair2");
  sf::Texture *wallPlatformTexture = graphicManager->GetTexture("wallPlatform");
  sf::Texture *doorTexture = graphicManager->GetTexture("door");

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp base platforms ------------------------------------------------------ */

  Platform *airPlatformBase = new Platform(graphicManager, static_cast<sf::Vector2f>(airPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *trapPlatformBase = new Platform(graphicManager, static_cast<sf::Vector2f>(trapPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *spikesBase = new Platform(graphicManager, static_cast<sf::Vector2f>(spikesTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *wallPlatformBase = new Platform(graphicManager, static_cast<sf::Vector2f>(wallPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));

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

  Platform *basePlatform = new Platform(graphicManager, sf::Vector2f(sizeX, 200.0f), sf::Vector2f(basePlatformPosition.x + (sizeX / 2.0f), basePlatformPosition.y + 100.0f));
  Platform *limitBorderYLeft = new Platform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(basePlatformPosition.x - 2.5f, basePlatformPosition.y / 2.0f));
  Platform *limitBorderYRight = new Platform(graphicManager, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(sizeX + 2.5f, basePlatformPosition.y / 2.0f));

  entities->InsertDynamicEntity(basePlatform);
  platforms.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  platforms.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  platforms.push_back(limitBorderYRight);

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp way to stairs ------------------------------------------------------- */

  Platform *airPlatform1 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(static_cast<float>(airPlatformTexture->getSize().x) / 2.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform2 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f((static_cast<float>(airPlatformTexture->getSize().x) / 2.0f) * 6.0f, basePlatformPosition.y - 300.0f));
  Platform *airPlatform3 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(static_cast<float>(airPlatformTexture->getSize().x) / 2.0f, basePlatformPosition.y - 450.0f));
  Platform *trapPlatform1 = new Platform(graphicManager, trapPlatformBase->GetSize(), sf::Vector2f((static_cast<float>(trapPlatformTexture->getSize().x) / 2.0f) * 6.0f, basePlatformPosition.y - 600.0f));
  Platform *airPlatform4 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f((static_cast<float>(trapPlatformTexture->getSize().x) / 2.0f) * 30.0f, basePlatformPosition.y - 600.0f));

  Item *stair = new Item(stairTexture, static_cast<sf::Vector2f>(stairTexture->getSize()), sf::Vector2f((static_cast<float>(trapPlatformTexture->getSize().x) / 2.0f) * 30.0f, basePlatformPosition.y - 600.0f - airPlatform4->GetHalfSize().y - (stairTexture->getSize().y / 2.0f)));
  stair->SetStair(true);

  entities->InsertDynamicEntity(airPlatform1);
  platforms.push_back(airPlatform1);
  entities->InsertDynamicEntity(airPlatform2);
  platforms.push_back(airPlatform2);
  entities->InsertDynamicEntity(airPlatform3);
  platforms.push_back(airPlatform3);
  entities->InsertDynamicEntity(trapPlatform1);
  platforms.push_back(trapPlatform1);
  entities->InsertDynamicEntity(airPlatform4);
  platforms.push_back(airPlatform4);

  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp First Spikes --------------------------------------------------------- */

  Platform *spikesFirst = new Platform(graphicManager, spikesBase->GetSize(), sf::Vector2f(airPlatform2->GetPosition().x + airPlatform2->GetHalfSize().x + (spikesTexture->getSize().x / 2.0f), basePlatformPosition.y - (spikesTexture->getSize().y / 2.0f)));
  entities->InsertDynamicEntity(spikesFirst);
  platforms.push_back(spikesFirst);

  Platform *spikesPrevious = spikesFirst;
  Platform *spikesLast = NULL;
  for (int i = 0; i < 12; i++)
  {
    spikesLast = new Platform(graphicManager, spikesBase->GetSize(), sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    platforms.push_back(spikesLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------ SetUp Ladder + Second Spikes + Air Platform ----------------------------------------------- */

  Platform *airPlatform5 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(spikesLast->GetPosition().x + spikesLast->GetSize().x + 1800.0f, basePlatformPosition.y - 150.0f));
  Platform *trapPlatform2 = new Platform(graphicManager, trapPlatformBase->GetSize(), sf::Vector2f(airPlatform5->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 300.0f));
  Platform *airPlatform6 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform2->GetPosition().x + (trapPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 450.0f));
  Platform *trapPlatform3 = new Platform(graphicManager, trapPlatformBase->GetSize(), sf::Vector2f(airPlatform6->GetPosition().x + (trapPlatformBase->GetSize().x * 5.0f), basePlatformPosition.y - 300.0f));
  Platform *airPlatform7 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform3->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f), basePlatformPosition.y - 450.0f));

  entities->InsertDynamicEntity(airPlatform5);
  platforms.push_back(airPlatform5);
  entities->InsertDynamicEntity(trapPlatform2);
  platforms.push_back(trapPlatform2);
  entities->InsertDynamicEntity(airPlatform6);
  platforms.push_back(airPlatform6);
  entities->InsertDynamicEntity(airPlatform7);
  platforms.push_back(airPlatform7);
  entities->InsertDynamicEntity(trapPlatform3);
  platforms.push_back(trapPlatform3);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  spikesFirst = new Platform(graphicManager, spikesBase->GetSize(), sf::Vector2f(spikesLast->GetPosition().x + spikesLast->GetSize().x + 1800.0f, basePlatformPosition.y - spikesBase->GetHalfSize().y));
  entities->InsertDynamicEntity(spikesFirst);
  platforms.push_back(spikesFirst);

  spikesPrevious = spikesFirst;
  spikesLast = NULL;
  for (int i = 0; i < 44; i++)
  {
    spikesLast = new Platform(graphicManager, spikesBase->GetSize(), sf::Vector2f(spikesPrevious->GetPosition().x + spikesPrevious->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    platforms.push_back(spikesLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  Platform *airPlatformFirst = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform3->GetPosition().x + (airPlatformBase->GetSize().x * 4.0f) + 500.0f, basePlatformPosition.y - 450.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  Platform *airPlatformPrevious = airPlatformFirst;
  Platform *airPlatformLast = NULL;
  for (int i = 0; i < 15; i++)
  {
    airPlatformLast = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, basePlatformPosition.y - 450.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------ SetUp Air Platform down + Leader to exit + Exit ------------------------------------------- */

  Platform *airPlatformLastBridge = airPlatformLast;

  airPlatformFirst = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatformLast->GetPosition().x + 500.0f, basePlatformPosition.y - 100.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  for (int i = 0; i < 1; i++)
  {
    airPlatformLast = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, basePlatformPosition.y - 100.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  Platform *airPlatform8 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(sizeX - airPlatformBase->GetHalfSize().x, basePlatformPosition.y - 250.0f));
  Platform *airPlatform9 = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatform8->GetPosition().x - 100.0f, basePlatformPosition.y - 400.0f));

  entities->InsertDynamicEntity(airPlatform8);
  platforms.push_back(airPlatform8);
  entities->InsertDynamicEntity(airPlatform9);
  platforms.push_back(airPlatform9);

  /* ----------------------------------------------------------------------------------------------------------------------------------- */

  airPlatformFirst = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatformLastBridge->GetPosition().x + 200.0f, airPlatformLastBridge->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  for (int i = 0; i < 5; i++)
  {
    airPlatformLast = new Platform(graphicManager, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformPrevious->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  Platform *wallPlatformFirst = new Platform(graphicManager, wallPlatformBase->GetSize(), sf::Vector2f(airPlatformFirst->GetPosition().x - airPlatformBase->GetHalfSize().x + wallPlatformBase->GetHalfSize().x, airPlatformFirst->GetPosition().y - airPlatformBase->GetHalfSize().y - wallPlatformBase->GetHalfSize().y));
  entities->InsertDynamicEntity(wallPlatformFirst);
  platforms.push_back(wallPlatformFirst);

  Platform *wallPlatformPrevious = wallPlatformFirst;
  Platform *wallPlatformLast = NULL;
  for (int i = 0; i < 5; i++)
  {
    wallPlatformLast = new Platform(graphicManager, wallPlatformBase->GetSize(), sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y - wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    platforms.push_back(wallPlatformLast);
  }

  Item *door = new Item(doorTexture, static_cast<sf::Vector2f>(doorTexture->getSize()), sf::Vector2f(airPlatformFirst->GetPosition().x + airPlatformBase->GetHalfSize().x, wallPlatformFirst->GetPosition().y + wallPlatformBase->GetHalfSize().y - ((float)doorTexture->getSize().y / 2.0f)));
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