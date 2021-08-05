#include "LevelSewer.h"
#include "GraphicManager.h"

LevelSewer::LevelSewer(GraphicManager *graphicManager) : Level()
{
  sizeX = 5000.0f;
  this->graphicManager = graphicManager;
  enemiesNum = 0;
}

LevelSewer::~LevelSewer()
{
}

void LevelSewer::Initialize()
{
  characters.InitializeCharacters(enemiesNum, &entities, graphicManager);
  //printf("ponteiro em LevelSewer: %p\n", graphicManager);  
  sf::Texture *backgroundTexture = graphicManager->GetTexture("levelOne");
  sf::Vector2u windowSize = graphicManager->GetWindow()->getSize();

  sf::Vector2f backgroundSize;
  backgroundSize.x = static_cast<float>(backgroundTexture->getSize().x);
  backgroundSize.y = static_cast<float>(windowSize.y);
  background.setSize(backgroundSize);
  background.setTexture(backgroundTexture);

  playerOne = static_cast<Player *>(characters.GetPlayer());

  static sf::Texture *plataformTexture = graphicManager->GetTexture("basePlatformTexture");

  sf::Vector2f basePlatformPosition;
  basePlatformPosition.x = 0.0f;
  basePlatformPosition.y = static_cast<float>(windowSize.y);

  Platform *basePlatform = new Platform(plataformTexture, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(basePlatformPosition.x + 2500.0f, basePlatformPosition.y + 50.0f));
  Platform *limitBorderYLeft = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(basePlatformPosition.x, basePlatformPosition.y / 2.0f));
  Platform *limitBorderYRight = new Platform(plataformTexture, sf::Vector2f(5.0f, basePlatformPosition.y), sf::Vector2f(5000.0f, basePlatformPosition.y / 2.0f));

  entities.InsertEntity(basePlatform);
  entities.InsertEntity(limitBorderYLeft);
  entities.InsertEntity(limitBorderYRight);

  playerOne->SetPosition(sf::Vector2f(31.0f, static_cast<float>(graphicManager->GetWindow()->getSize().y) - 36.0f));

  /* --------------------------------------------------------- SetUp Spikes --------------------------------------------------------- */

  static sf::Texture *spikesTexture = graphicManager->GetTexture("spikesTexture");

  Platform *spikes1 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(300.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes2 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(364.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes3 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(428.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes4 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(492.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes5 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(556.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes6 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(620.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes7 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(684.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));
  Platform *spikes8 = new Platform(spikesTexture, sf::Vector2f(64.0f, 15.0f), sf::Vector2f(748.0f, basePlatformPosition.y - (static_cast<float>(spikesTexture->getSize().y) / 2.0f)));

  entities.InsertEntity(spikes1);
  entities.InsertEntity(spikes2);
  entities.InsertEntity(spikes3);
  entities.InsertEntity(spikes4);
  entities.InsertEntity(spikes5);
  entities.InsertEntity(spikes6);
  entities.InsertEntity(spikes7);
  entities.InsertEntity(spikes8);

  /* --------------------------------------------------------- SetUp First Air Platform --------------------------------------------------------- */

  static sf::Texture airPlatformTexture;
  if (!airPlatformTexture.loadFromFile("assets/background/air_platform.png"))
    cerr << "Error loading airPlatform texture" << endl;

  Platform *airPlatform1 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(748.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform2 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(794.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform3 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(840.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform4 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(886.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform5 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(932.0f, basePlatformPosition.y - 50.0f));
  Platform *airPlatform6 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(978.0f, basePlatformPosition.y - 50.0f));

  entities.InsertEntity(airPlatform1);
  entities.InsertEntity(airPlatform2);
  entities.InsertEntity(airPlatform3);
  entities.InsertEntity(airPlatform4);
  entities.InsertEntity(airPlatform5);
  entities.InsertEntity(airPlatform6);

  /* --------------------------------------------------------- SetUp Platform to Stair --------------------------------------------------------- */

  Platform *airPlatform7 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2078.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform8 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2124.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform9 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2170.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform10 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2216.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform11 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2262.0f, basePlatformPosition.y - 150.0f));
  Platform *airPlatform12 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2308.0f, basePlatformPosition.y - 150.0f));

  entities.InsertEntity(airPlatform7);
  entities.InsertEntity(airPlatform8);
  entities.InsertEntity(airPlatform9);
  entities.InsertEntity(airPlatform10);
  entities.InsertEntity(airPlatform11);
  entities.InsertEntity(airPlatform12);

  static sf::Texture wallPlatformTexture;
  if (!wallPlatformTexture.loadFromFile("assets/background/air_platform.png"))
    cerr << "Error loading walPlatform texture" << endl;

  Platform *wallPlatform1 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 180.0f));
  Platform *wallPlatform2 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 226.0f));
  Platform *wallPlatform3 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 270.0f));
  Platform *wallPlatform4 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(2322.0f, basePlatformPosition.y - 316.0f));

  entities.InsertEntity(wallPlatform1);
  entities.InsertEntity(wallPlatform2);
  entities.InsertEntity(wallPlatform3);
  entities.InsertEntity(wallPlatform4);

  Platform *airPlatform13 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2351.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform14 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2397.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform15 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2443.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform16 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2489.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform17 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2535.5f, basePlatformPosition.y - 332.0f));
  Platform *airPlatform18 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(2581.5f, basePlatformPosition.y - 332.0f));

  entities.InsertEntity(airPlatform13);
  entities.InsertEntity(airPlatform14);
  entities.InsertEntity(airPlatform15);
  entities.InsertEntity(airPlatform16);
  entities.InsertEntity(airPlatform17);
  entities.InsertEntity(airPlatform18);

  static sf::Texture stairTexture;
  if (!stairTexture.loadFromFile("assets/background/stair1.png"))
    cerr << "Error loading voidstair1 texture" << endl;

  Platform *stair = new Platform(&stairTexture, sf::Vector2f(35.0f, 39.0f), sf::Vector2f(2581.5f, basePlatformPosition.y - 372.0f));

  entities.InsertEntity(stair);

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

  entities.InsertEntity(spikes9);
  entities.InsertEntity(spikes10);
  entities.InsertEntity(spikes11);
  entities.InsertEntity(spikes12);
  entities.InsertEntity(spikes13);
  entities.InsertEntity(spikes14);
  entities.InsertEntity(spikes15);
  entities.InsertEntity(spikes16);
  entities.InsertEntity(spikes17);
  entities.InsertEntity(spikes18);
  entities.InsertEntity(spikes19);
  entities.InsertEntity(spikes20);

  Platform *airPlatform19 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3180.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform20 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3226.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform21 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3272.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform22 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3318.5f, basePlatformPosition.y - 30.0f));
  Platform *airPlatform23 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(3364.5f, basePlatformPosition.y - 30.0f));

  entities.InsertEntity(airPlatform19);
  entities.InsertEntity(airPlatform20);
  entities.InsertEntity(airPlatform21);
  entities.InsertEntity(airPlatform22);
  entities.InsertEntity(airPlatform23);

  /* --------------------------------------------------------- SetUp Exit Platform --------------------------------------------------------- */

  Platform *wallPlatform5 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 23.0f));
  Platform *wallPlatform6 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 69.0f));
  Platform *wallPlatform7 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 115.0f));
  Platform *wallPlatform8 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4164.0f, basePlatformPosition.y - 161.0f));

  entities.InsertEntity(wallPlatform5);
  entities.InsertEntity(wallPlatform6);
  entities.InsertEntity(wallPlatform7);
  entities.InsertEntity(wallPlatform8);

  Platform *airPlatform24 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4195.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform25 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4241.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform26 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4287.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform27 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4333.5f, basePlatformPosition.y - 177.0f));
  Platform *airPlatform28 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4379.5f, basePlatformPosition.y - 177.0f));

  entities.InsertEntity(airPlatform24);
  entities.InsertEntity(airPlatform25);
  entities.InsertEntity(airPlatform26);
  entities.InsertEntity(airPlatform27);
  entities.InsertEntity(airPlatform28);

  Platform *wallPlatform9 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 207.0f));
  Platform *wallPlatform10 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 253.0f));
  Platform *wallPlatform11 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 299.0f));
  Platform *wallPlatform12 = new Platform(&airPlatformTexture, sf::Vector2f(16.0f, 46.0f), sf::Vector2f(4394.0f, basePlatformPosition.y - 345.0f));

  entities.InsertEntity(wallPlatform9);
  entities.InsertEntity(wallPlatform10);
  entities.InsertEntity(wallPlatform11);
  entities.InsertEntity(wallPlatform12);

  Platform *airPlatform29 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4425.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform30 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4471.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform31 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4517.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform32 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4563.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform33 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4609.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform34 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4655.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform35 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4701.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform36 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4747.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform37 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4793.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform38 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4839.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform39 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4885.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform40 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4931.0f, basePlatformPosition.y - 361.0f));
  Platform *airPlatform41 = new Platform(&airPlatformTexture, sf::Vector2f(46.0f, 14.0f), sf::Vector2f(4977.0f, basePlatformPosition.y - 361.0f));

  entities.InsertEntity(airPlatform29);
  entities.InsertEntity(airPlatform30);
  entities.InsertEntity(airPlatform31);
  entities.InsertEntity(airPlatform32);
  entities.InsertEntity(airPlatform33);
  entities.InsertEntity(airPlatform34);
  entities.InsertEntity(airPlatform35);
  entities.InsertEntity(airPlatform36);
  entities.InsertEntity(airPlatform37);
  entities.InsertEntity(airPlatform38);
  entities.InsertEntity(airPlatform39);
  entities.InsertEntity(airPlatform40);
  entities.InsertEntity(airPlatform41);

  static sf::Texture doorTexture;
  if (!doorTexture.loadFromFile("assets/background/door.png"))
    cerr << "Error loading door texture" << endl;

  Platform *door = new Platform(&doorTexture, sf::Vector2f(69.0f, 113.0f), sf::Vector2f(4931.0f, basePlatformPosition.y - 424.5f));

  entities.InsertEntity(door);
}