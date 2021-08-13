#include "LevelOverground.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "Platform.h"
#include "Item.h"

LevelOverground::LevelOverground(GraphicManager *graphicManager, ColliderManager *graphicCollider) : Level(graphicManager, graphicCollider)
{
  sizeX = 5400.0f;
  enemiesNum = 0;
}

LevelOverground::~LevelOverground()
{
}

void LevelOverground::InitializeCharacters()
{
  Player *playerOne = new Player(graphicManager->GetTexture("playerOne"), sf::Vector2f(60.0f, 40.0f), sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 200.0f), sf::Vector2u(4, 4), 0.30f, 200.0f, 200.0f, 300, true, true, true);
  characters.push_back(playerOne);
  entities->InsertDynamicEntity(playerOne);
  SetPlayerOne(playerOne);

  for (int i = 0; i < enemiesNum; i++)
  {
    sf::Vector2f enemyPosistion;
    enemyPosistion.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion.y = 0.0f;

    Enemy *aux = NULL;
    aux = new Enemy(graphicManager->GetTexture("enemyMelee"), sf::Vector2f(100, 100), enemyPosistion, sf::Vector2u(6, 2), 0.3f, 100.0f, 100.0f, 5.0f, false, true);
    characters.push_back(aux);
    entities->InsertDynamicEntity(aux);
  }
}

void LevelOverground::Initialize()
{
  /* --------------------------------------------------------- Getting textures --------------------------------------------------------- */

  sf::Texture *backgroundTexture = graphicManager->GetTexture("levelThree");
  sf::Texture *plataformTexture = graphicManager->GetTexture("basePlatformTexture");
  sf::Texture *airPlatformTexture = graphicManager->GetTexture("airPlatform");
  sf::Texture *trapPlatformTexture = graphicManager->GetTexture("trapPlatform");
  sf::Texture *spikesTexture = graphicManager->GetTexture("spikes");
  sf::Texture *stairTexture = graphicManager->GetTexture("stair3");
  sf::Texture *wallPlatformTexture = graphicManager->GetTexture("wallPlatform");
  sf::Texture *doorTexture = graphicManager->GetTexture("door");

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp base platforms ------------------------------------------------------ */

  Platform *airPlatformBase = new Platform(airPlatformTexture, static_cast<sf::Vector2f>(airPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *trapPlatformBase = new Platform(trapPlatformTexture, static_cast<sf::Vector2f>(trapPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *spikesBase = new Platform(spikesTexture, static_cast<sf::Vector2f>(spikesTexture->getSize()), sf::Vector2f(0.0f, 0.0f));
  Platform *wallPlatformBase = new Platform(wallPlatformTexture, static_cast<sf::Vector2f>(wallPlatformTexture->getSize()), sf::Vector2f(0.0f, 0.0f));

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

  Platform *basePlatform = new Platform(plataformTexture, sf::Vector2f(sizeX, 200.0f), sf::Vector2f(basePlatformPosition.x + (sizeX / 2.0f), basePlatformPosition.y + 100.0f));
  Platform *limitBorderYLeft = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(basePlatformPosition.x - 2.5f, basePlatformPosition.y / 2.0f));
  Platform *limitBorderYRight = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y + 300.0f), sf::Vector2f(sizeX + 2.5f, basePlatformPosition.y / 2.0f));

  entities->InsertDynamicEntity(basePlatform);
  platforms.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  platforms.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  platforms.push_back(limitBorderYRight);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* --------------------------------------------------------- SetUp spikes on floor ------------------------------------------------------- */

  Platform *spikesFirst = new Platform(spikesTexture, spikesBase->GetSize(), sf::Vector2f(spikesBase->GetHalfSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
  entities->InsertDynamicEntity(spikesFirst);
  platforms.push_back(spikesFirst);

  Platform *spikesPrevious = spikesFirst;
  Platform *spikesLast = NULL;
  for (int i = 0; i < 84; i++)
  {
    spikesLast = new Platform(spikesTexture, spikesBase->GetSize(), sf::Vector2f(spikesPrevious->GetPosition().x + spikesBase->GetSize().x, basePlatformPosition.y - spikesBase->GetHalfSize().y));
    spikesPrevious = spikesLast;
    entities->InsertDynamicEntity(spikesLast);
    platforms.push_back(spikesLast);
  }

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  /* ------------------------------------------------ SetUp 2Traps + Air platform + 1Trap ------------------------------------------------ */

  Platform *trapPlatform1 = new Platform(trapPlatformTexture, trapPlatformBase->GetSize(), sf::Vector2f(trapPlatformBase->GetHalfSize().x, basePlatformPosition.y - 150.0f));
  Platform *trapPlatform2 = new Platform(trapPlatformTexture, trapPlatformBase->GetSize(), sf::Vector2f(trapPlatform1->GetPosition().x + trapPlatformBase->GetSize().x, basePlatformPosition.y - 150.0f));

  entities->InsertDynamicEntity(trapPlatform1);
  platforms.push_back(trapPlatform1);
  entities->InsertDynamicEntity(trapPlatform2);
  platforms.push_back(trapPlatform2);

  Platform *airPlatform1 = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform2->GetPosition().x + 600.0f, basePlatformPosition.y - 150.0f));
  entities->InsertDynamicEntity(airPlatform1);
  platforms.push_back(airPlatform1);

  Platform *airPlatformFirst = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatform1->GetPosition().x + 600.0f, basePlatformPosition.y - 150.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  Platform *airPlatformPrevious = airPlatformFirst;
  Platform *airPlatformLast = NULL;
  for (int i = 0; i < 12; i++)
  {
    airPlatformLast = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 150.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  Platform *trapPlatform3 = new Platform(trapPlatformTexture, trapPlatformBase->GetSize(), sf::Vector2f(airPlatformLast->GetPosition().x + 400.0f, basePlatformPosition.y - 300.0f));
  entities->InsertDynamicEntity(trapPlatform3);
  platforms.push_back(trapPlatform3);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* -------------------------------------------------- SetUp Part of Stair --------------------------------------------------------------- */

  airPlatformFirst = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform3->GetPosition().x + 600.0f, basePlatformPosition.y - 300.0f));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 22; i++)
  {
    airPlatformLast = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - 300.0f));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  Platform *wallPlatformFirst = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatformFirst->GetPosition().x - airPlatformBase->GetHalfSize().x + wallPlatformBase->GetHalfSize().x, basePlatformPosition.y - 300.0f + airPlatformBase->GetHalfSize().y - wallPlatformBase->GetHalfSize().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  Platform *wallPlatformPrevious = wallPlatformFirst;
  Platform *wallPlatformLast = NULL;
  for (int i = 0; i < 5; i++)
  {
    wallPlatformLast = new Platform(wallPlatformTexture, wallPlatformBase->GetSize(), sf::Vector2f(wallPlatformPrevious->GetPosition().x, wallPlatformPrevious->GetPosition().y + wallPlatformBase->GetSize().y));
    wallPlatformPrevious = wallPlatformLast;
    entities->InsertDynamicEntity(wallPlatformLast);
    platforms.push_back(wallPlatformLast);
  }

  Platform *trapPlatform4 = new Platform(trapPlatformTexture, trapPlatformBase->GetSize(), sf::Vector2f(airPlatformLast->GetPosition().x + airPlatformBase->GetSize().x, basePlatformPosition.y - spikesBase->GetSize().y - 20.0f));
  entities->InsertDynamicEntity(trapPlatform4);
  platforms.push_back(trapPlatform4);

  airPlatformFirst = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform4->GetPosition().x - 150.0f, trapPlatform4->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 10; i++)
  {
    airPlatformLast = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x - airPlatformBase->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  Platform *trapPlatform5 = new Platform(trapPlatformTexture, trapPlatformBase->GetSize(), sf::Vector2f(wallPlatformLast->GetPosition().x + wallPlatformBase->GetHalfSize().x + trapPlatformBase->GetHalfSize().x + 10.0f, airPlatformLast->GetPosition().y));
  entities->InsertDynamicEntity(trapPlatform5);
  platforms.push_back(trapPlatform5);

  Item *stair = new Item(stairTexture, static_cast<sf::Vector2f>(stairTexture->getSize()), sf::Vector2f(trapPlatform5->GetPosition().x, trapPlatform5->GetPosition().y - trapPlatformBase->GetHalfSize().y - ((float)stairTexture->getSize().y / 2.0f)));
  stair->SetStair(true);
  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  /* -------------------------------------------------------------------------------------------------------------------------------------- */

  /* -------------------------------------------------------- SetUp Exit ------------------------------------------------------------------ */

  airPlatformFirst = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(trapPlatform4->GetPosition().x + 600.0f, trapPlatform4->GetPosition().y));
  entities->InsertDynamicEntity(airPlatformFirst);
  platforms.push_back(airPlatformFirst);

  airPlatformPrevious = airPlatformFirst;
  airPlatformLast = NULL;
  for (int i = 0; i < 20; i++)
  {
    airPlatformLast = new Platform(airPlatformTexture, airPlatformBase->GetSize(), sf::Vector2f(airPlatformPrevious->GetPosition().x + airPlatformBase->GetSize().x, airPlatformPrevious->GetPosition().y));
    airPlatformPrevious = airPlatformLast;
    entities->InsertDynamicEntity(airPlatformLast);
    platforms.push_back(airPlatformLast);
  }

  Item *door = new Item(doorTexture, static_cast<sf::Vector2f>(doorTexture->getSize()), sf::Vector2f(airPlatformLast->GetPosition().x - (2 * airPlatformBase->GetSize().x), airPlatformLast->GetPosition().y - airPlatformBase->GetHalfSize().y - ((float)doorTexture->getSize().y / 2.0f)));
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