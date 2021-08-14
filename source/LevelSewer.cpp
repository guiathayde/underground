#include "LevelSewer.h"
#include "GraphicManager.h"
#include "Enemy.h"
#include "Platform.h"
#include "Item.h"

LevelSewer::LevelSewer(GraphicManager *graphicManager, ColliderManager *graphicCollider) : Level(graphicManager, graphicCollider)
{
  nameLevel = "Sewer";
  sizeX = 5000.0f;
  enemiesNum = 6;
  nextLevel = 2;
}

LevelSewer::~LevelSewer()
{
}

void LevelSewer::InitializeCharacters()
{
  Player *playerOne = new Player(graphicManager->GetTexture("playerOne"), sf::Vector2f(60.0f, 40.0f), sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 21.0f), sf::Vector2u(4, 4), 0.30f, 200.0f, 200.0f, 300, true, true, true);
  characters.push_back(playerOne);
  entities->InsertDynamicEntity(playerOne);
  SetPlayerOne(playerOne);

  for (int i = 0; i < enemiesNum; i++)
  {
    sf::Vector2f enemyPosistion;
    enemyPosistion.x = static_cast<float>((rand() % 3000) + 1200);
    enemyPosistion.y = 0.0f;

    Enemy *aux = new Enemy(graphicManager->GetTexture("enemyMelee"), sf::Vector2f(100, 100), enemyPosistion, sf::Vector2u(6, 2), 0.3f, 100.0f, 100.0f, 5.0f, false, true);
    characters.push_back(aux);
    entities->InsertDynamicEntity(aux);
  }
}

void LevelSewer::Initialize()
{
  /* --------------------------------------------------------- Getting textures --------------------------------------------------------- */

  sf::Texture *backgroundTexture = graphicManager->GetTexture("levelOne");
  sf::Texture *plataformTexture = graphicManager->GetTexture("basePlatformTexture");
  sf::Texture *airPlatformTexture = graphicManager->GetTexture("airPlatform");
  sf::Texture *spikesTexture = graphicManager->GetTexture("spikes");
  sf::Texture *stairTexture = graphicManager->GetTexture("stair1");
  sf::Texture *wallPlatformTexture = graphicManager->GetTexture("wallPlatform");
  sf::Texture *doorTexture = graphicManager->GetTexture("door");

  /* ------------------------------------------------------------------------------------------------------------------------------------- */

  sf::Vector2u windowSize = graphicManager->GetWindow()->getSize();

  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture->getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(backgroundTexture);

  sf::Vector2f basePlatformPosition;
  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);

  Platform *basePlatform = new Platform(plataformTexture, sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(basePlatformPosition.x + 2500.0f, basePlatformPosition.y + 100.0f));
  Platform *limitBorderYLeft = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y / 2.0f));
  Platform *limitBorderYRight = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(5000.0f, basePlatformPosition.y / 2.0f));

  entities->InsertDynamicEntity(basePlatform);
  platforms.push_back(basePlatform);
  entities->InsertDynamicEntity(limitBorderYLeft);
  platforms.push_back(limitBorderYLeft);
  entities->InsertDynamicEntity(limitBorderYRight);
  platforms.push_back(limitBorderYRight);

  /* --------------------------------------------------------- SetUp Spikes --------------------------------------------------------- */

  Platform *spikes1 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(300.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes2 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(364.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes3 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(428.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes4 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(492.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes5 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(556.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes6 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(620.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes7 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(684.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes8 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(748.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));

  entities->InsertDynamicEntity(spikes1);
  platforms.push_back(spikes1);
  entities->InsertDynamicEntity(spikes2);
  platforms.push_back(spikes2);
  entities->InsertDynamicEntity(spikes3);
  platforms.push_back(spikes3);
  entities->InsertDynamicEntity(spikes4);
  platforms.push_back(spikes4);
  entities->InsertDynamicEntity(spikes5);
  platforms.push_back(spikes5);
  entities->InsertDynamicEntity(spikes6);
  platforms.push_back(spikes6);
  entities->InsertDynamicEntity(spikes7);
  platforms.push_back(spikes7);
  entities->InsertDynamicEntity(spikes8);
  platforms.push_back(spikes8);

  /* --------------------------------------------------------- SetUp First Air Platform --------------------------------------------------------- */

  Platform *airPlatform1 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(748.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform2 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(794.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform3 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(840.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform4 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(886.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform5 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(932.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform6 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(978.0f, basePlatformPosition.y - 50.0f));

  entities->InsertDynamicEntity(airPlatform1);
  platforms.push_back(airPlatform1);
  entities->InsertDynamicEntity(airPlatform2);
  platforms.push_back(airPlatform2);
  entities->InsertDynamicEntity(airPlatform3);
  platforms.push_back(airPlatform3);
  entities->InsertDynamicEntity(airPlatform4);
  platforms.push_back(airPlatform4);
  entities->InsertDynamicEntity(airPlatform5);
  platforms.push_back(airPlatform5);
  entities->InsertDynamicEntity(airPlatform6);
  platforms.push_back(airPlatform6);

  /* --------------------------------------------------------- SetUp Platform to Stair --------------------------------------------------------- */

  Platform *airPlatform7 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2078.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform8 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2124.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform9 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2170.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform10 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2216.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform11 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2262.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform12 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2308.0f, basePlatformPosition.y - 150.0f));

  entities->InsertDynamicEntity(airPlatform7);
  platforms.push_back(airPlatform7);
  entities->InsertDynamicEntity(airPlatform8);
  platforms.push_back(airPlatform8);
  entities->InsertDynamicEntity(airPlatform9);
  platforms.push_back(airPlatform9);
  entities->InsertDynamicEntity(airPlatform10);
  platforms.push_back(airPlatform10);
  entities->InsertDynamicEntity(airPlatform11);
  platforms.push_back(airPlatform11);
  entities->InsertDynamicEntity(airPlatform12);
  platforms.push_back(airPlatform12);

  Platform *wallPlatform1 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 180.0f));
  Platform *wallPlatform2 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 226.0f));
  Platform *wallPlatform3 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 270.0f));
  Platform *wallPlatform4 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 316.0f));

  entities->InsertDynamicEntity(wallPlatform1);
  platforms.push_back(wallPlatform1);
  entities->InsertDynamicEntity(wallPlatform2);
  platforms.push_back(wallPlatform2);
  entities->InsertDynamicEntity(wallPlatform3);
  platforms.push_back(wallPlatform3);
  entities->InsertDynamicEntity(wallPlatform4);
  platforms.push_back(wallPlatform4);

  Platform *airPlatform13 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2351.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform14 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2397.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform15 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2443.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform16 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2489.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform17 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2535.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform18 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2581.5f, basePlatformPosition.y - 332.0f));

  entities->InsertDynamicEntity(airPlatform13);
  platforms.push_back(airPlatform13);
  entities->InsertDynamicEntity(airPlatform14);
  platforms.push_back(airPlatform14);
  entities->InsertDynamicEntity(airPlatform15);
  platforms.push_back(airPlatform15);
  entities->InsertDynamicEntity(airPlatform16);
  platforms.push_back(airPlatform16);
  entities->InsertDynamicEntity(airPlatform17);
  platforms.push_back(airPlatform17);
  entities->InsertDynamicEntity(airPlatform18);
  platforms.push_back(airPlatform18);

  Item *stair = new Item(stairTexture, sf::Vector2f(35.0f, 39.0f), sf::Vector2f(2581.5f, basePlatformPosition.y - 372.0f));
  stair->SetStair(true);

  entities->InsertDynamicEntity(stair);
  items.push_back(stair);

  /* --------------------------------------------------------- SetUp Spikes and AirPlatform --------------------------------------------------------- */

  Platform *spikes9 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2604.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes10 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2668.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes11 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2732.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes12 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2796.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes13 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2860.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes14 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2924.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes15 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(2988.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes16 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(3052.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes17 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(3116.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes18 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(3180.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes19 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(3244.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes20 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(3308.5f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));

  entities->InsertDynamicEntity(spikes9);
  platforms.push_back(spikes9);
  entities->InsertDynamicEntity(spikes10);
  platforms.push_back(spikes10);
  entities->InsertDynamicEntity(spikes11);
  platforms.push_back(spikes11);
  entities->InsertDynamicEntity(spikes12);
  platforms.push_back(spikes12);
  entities->InsertDynamicEntity(spikes13);
  platforms.push_back(spikes13);
  entities->InsertDynamicEntity(spikes14);
  platforms.push_back(spikes14);
  entities->InsertDynamicEntity(spikes15);
  platforms.push_back(spikes15);
  entities->InsertDynamicEntity(spikes16);
  platforms.push_back(spikes16);
  entities->InsertDynamicEntity(spikes17);
  platforms.push_back(spikes17);
  entities->InsertDynamicEntity(spikes18);
  platforms.push_back(spikes18);
  entities->InsertDynamicEntity(spikes19);
  platforms.push_back(spikes19);
  entities->InsertDynamicEntity(spikes20);
  platforms.push_back(spikes20);

  Platform *airPlatform19 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3180.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform20 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3226.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform21 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3272.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform22 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3318.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform23 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3364.5f, basePlatformPosition.y - 30.0f));

  entities->InsertDynamicEntity(airPlatform19);
  platforms.push_back(airPlatform19);
  entities->InsertDynamicEntity(airPlatform20);
  platforms.push_back(airPlatform20);
  entities->InsertDynamicEntity(airPlatform21);
  platforms.push_back(airPlatform21);
  entities->InsertDynamicEntity(airPlatform22);
  platforms.push_back(airPlatform22);
  entities->InsertDynamicEntity(airPlatform23);
  platforms.push_back(airPlatform23);

  /* --------------------------------------------------------- SetUp Exit Platform --------------------------------------------------------- */

  Platform *wallPlatform5 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 23.0f));
  Platform *wallPlatform6 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 69.0f));
  Platform *wallPlatform7 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 115.0f));
  Platform *wallPlatform8 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 161.0f));

  entities->InsertDynamicEntity(wallPlatform5);
  platforms.push_back(wallPlatform5);
  entities->InsertDynamicEntity(wallPlatform6);
  platforms.push_back(wallPlatform6);
  entities->InsertDynamicEntity(wallPlatform7);
  platforms.push_back(wallPlatform7);
  entities->InsertDynamicEntity(wallPlatform8);
  platforms.push_back(wallPlatform8);

  Platform *airPlatform24 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4195.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform25 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4241.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform26 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4287.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform27 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4333.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform28 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4379.5f, basePlatformPosition.y - 177.0f));

  entities->InsertDynamicEntity(airPlatform24);
  platforms.push_back(airPlatform24);
  entities->InsertDynamicEntity(airPlatform25);
  platforms.push_back(airPlatform25);
  entities->InsertDynamicEntity(airPlatform26);
  platforms.push_back(airPlatform26);
  entities->InsertDynamicEntity(airPlatform27);
  platforms.push_back(airPlatform27);
  entities->InsertDynamicEntity(airPlatform28);
  platforms.push_back(airPlatform28);

  Platform *wallPlatform9 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 207.0f));
  Platform *wallPlatform10 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 253.0f));
  Platform *wallPlatform11 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 299.0f));
  Platform *wallPlatform12 = new Platform(airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 345.0f));

  entities->InsertDynamicEntity(wallPlatform9);
  platforms.push_back(wallPlatform9);
  entities->InsertDynamicEntity(wallPlatform10);
  platforms.push_back(wallPlatform10);
  entities->InsertDynamicEntity(wallPlatform11);
  platforms.push_back(wallPlatform11);
  entities->InsertDynamicEntity(wallPlatform12);
  platforms.push_back(wallPlatform12);

  Platform *airPlatform29 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4425.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform30 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4471.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform31 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4517.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform32 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4563.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform33 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4609.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform34 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4655.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform35 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4701.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform36 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4747.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform37 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4793.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform38 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4839.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform39 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4885.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform40 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4931.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform41 = new Platform(airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4977.0f, basePlatformPosition.y - 361.0f));

  entities->InsertDynamicEntity(airPlatform29);
  platforms.push_back(airPlatform29);
  entities->InsertDynamicEntity(airPlatform30);
  platforms.push_back(airPlatform30);
  entities->InsertDynamicEntity(airPlatform31);
  platforms.push_back(airPlatform31);
  entities->InsertDynamicEntity(airPlatform32);
  platforms.push_back(airPlatform32);
  entities->InsertDynamicEntity(airPlatform33);
  platforms.push_back(airPlatform33);
  entities->InsertDynamicEntity(airPlatform34);
  platforms.push_back(airPlatform34);
  entities->InsertDynamicEntity(airPlatform35);
  platforms.push_back(airPlatform35);
  entities->InsertDynamicEntity(airPlatform36);
  platforms.push_back(airPlatform36);
  entities->InsertDynamicEntity(airPlatform37);
  platforms.push_back(airPlatform37);
  entities->InsertDynamicEntity(airPlatform38);
  platforms.push_back(airPlatform38);
  entities->InsertDynamicEntity(airPlatform39);
  platforms.push_back(airPlatform39);
  entities->InsertDynamicEntity(airPlatform40);
  platforms.push_back(airPlatform40);
  entities->InsertDynamicEntity(airPlatform41);
  platforms.push_back(airPlatform41);

  Item *door = new Item(doorTexture, sf::Vector2f(69.0f, 113.0f), sf::Vector2f(4931.0f, basePlatformPosition.y - 424.5f));
  door->SetDoor(true);

  entities->InsertDynamicEntity(door);
  items.push_back(door);

  InitializeCharacters();
}