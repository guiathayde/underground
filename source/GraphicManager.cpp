#include "stdfx.h"
#include "GraphicManager.h"
#include "Level.h"
#include "Player.h"

GraphicManager::GraphicManager()
{
  window = new sf::RenderWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  view = new sf::View(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  LoadTexture();
}

GraphicManager::~GraphicManager()
{
  delete (window);
  delete (view);
}

void GraphicManager::InsertTexture(const char *name, sf::Texture *texture)
{
  textures.emplace(name, texture);
}

sf::Texture *GraphicManager::GetTexture(const char *name)
{
  map<const char *, sf::Texture *>::iterator itr = textures.begin();

  while (itr != textures.end())
  {
    if (!strcmp(itr->first, name))
      return itr->second;
    itr++;
  }
  return NULL;
}
void GraphicManager::ResizeView()
{
  float aspectRatio = float(window->getSize().x / float(window->getSize().y));
  view->setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void GraphicManager::LoadTexture()
{
  sf::Texture *mainMenuBackgroundTexture = new sf::Texture();
  if (!mainMenuBackgroundTexture->loadFromFile("assets/background/mainMenuBackground.png"))
    cerr << "Error loading mainMenuBackgroundTexture" << endl;
  InsertTexture("mainMenuBackgroundTexture", mainMenuBackgroundTexture);

  sf::Texture *levelOneThumbTexture = new sf::Texture();
  if (!levelOneThumbTexture->loadFromFile("assets/background/levelOneThumb.png"))
    cerr << "Error loading levelOneThumbTexture" << endl;
  InsertTexture("levelOneThumbTexture", levelOneThumbTexture);

  sf::Texture *levelTwoThumbTexture = new sf::Texture();
  if (!levelTwoThumbTexture->loadFromFile("assets/background/levelTwoThumb.png"))
    cerr << "Error loading levelTwoThumbTexture" << endl;
  InsertTexture("levelTwoThumbTexture", levelTwoThumbTexture);

  sf::Texture *levelThreeThumbTexture = new sf::Texture();
  if (!levelThreeThumbTexture->loadFromFile("assets/background/levelThreeThumb.png"))
    cerr << "Error loading levelThreeThumbTexture" << endl;
  InsertTexture("levelThreeThumbTexture", levelThreeThumbTexture);

  sf::Texture *basePlataformTexture = new sf::Texture();
  if (!basePlataformTexture->loadFromFile("assets/background/Plataforms/teste.png"))
    cerr << "Error loading platform texture" << endl;
  InsertTexture("basePlataformTexture", basePlataformTexture);

  sf::Texture *spikesTexture = new sf::Texture();
  if (!spikesTexture->loadFromFile("assets/background/spikes.png"))
    cerr << "Erro loading spikes texture" << endl;
  InsertTexture("spikes", spikesTexture);

  sf::Texture *enemyMeleeTexture = new sf::Texture();
  if (!enemyMeleeTexture->loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    cerr << "Error loading enemyMeleeTexture texture" << endl;
  InsertTexture("enemyMelee", enemyMeleeTexture);

  sf::Texture *enemyShooterTexture = new sf::Texture();
  if (!enemyShooterTexture->loadFromFile("assets/characters/EnemyShooter/enemy_shooter.png"))
    cerr << "Error loading enemyShooterTexture texture" << endl;
  InsertTexture("enemyShooter", enemyShooterTexture);

  sf::Texture *trashMonster = new sf::Texture();
  if(!trashMonster->loadFromFile("assets/characters/Trash Monster/trash_monster.png"))
    cerr << "Errot loading trashMonster texture" << endl;
  InsertTexture("trashMonster",trashMonster);

  sf::Texture *playerOneTexture = new sf::Texture();
  if (!playerOneTexture->loadFromFile("assets/characters/PlayerOne/playerV2.png"))
    cerr << "Error loading playerOneTexture texture" << endl;
  InsertTexture("playerOne", playerOneTexture);

  sf::Texture *sewerBackgroundTexture = new sf::Texture();
  if (!sewerBackgroundTexture->loadFromFile("assets/background/levelOne.png"))
    cerr << "Erro loading sewerBackgroundTexture" << endl;
  InsertTexture("levelOne", sewerBackgroundTexture);

  sf::Texture *subwayBackgroundTexture = new sf::Texture();
  if (!subwayBackgroundTexture->loadFromFile("assets/background/levelTwo.png"))
    cerr << "Erro loading subwayBackgroundTexture" << endl;
  InsertTexture("levelTwo", subwayBackgroundTexture);

  sf::Texture *airPlatformTexture = new sf::Texture();
  if (!airPlatformTexture->loadFromFile("assets/background/air_platform.png"))
    cerr << "Erro loading airPlatformTexture" << endl;
  InsertTexture("airPlatform", airPlatformTexture);

  sf::Texture *wallPlatformTexture = new sf::Texture();
  if (!wallPlatformTexture->loadFromFile("assets/background/wall_platform.png"))
    cerr << "Erro loading wallPlatformTexture" << endl;
  InsertTexture("wallPlatform", wallPlatformTexture);

  sf::Texture *doorTexture = new sf::Texture();
  if (!doorTexture->loadFromFile("assets/background/door.png"))
    cerr << "Erro loading doorTexture" << endl;
  InsertTexture("door", doorTexture);

  sf::Texture *trapPlatformTexture = new sf::Texture();
  if (!trapPlatformTexture->loadFromFile("assets/background/trap_platform.png"))
    cerr << "Erro loading trapPlatformTexture" << endl;
  InsertTexture("trapPlatform", trapPlatformTexture);

  sf::Texture *stair1Texture = new sf::Texture();
  if (!stair1Texture->loadFromFile("assets/background/stair1.png"))
    cerr << "Erro loading stair1Texture" << endl;
  InsertTexture("stair1", stair1Texture);

  sf::Texture *stair2Texture = new sf::Texture();
  if (!stair2Texture->loadFromFile("assets/background/stair2.png"))
    cerr << "Erro loading stair2Texture" << endl;
  InsertTexture("stair2", stair2Texture);

  sf::Texture *overgroundBackgroundTexture = new sf::Texture();
  if (!overgroundBackgroundTexture->loadFromFile("assets/background/levelThree.png"))
    cerr << "Erro loading overgroundBackgroundTexture" << endl;
  InsertTexture("levelThree", overgroundBackgroundTexture);

  sf::Texture *stair3Texture = new sf::Texture();
  if (!stair3Texture->loadFromFile("assets/background/stair3.png"))
    cerr << "Erro loading stair2Texture" << endl;
  InsertTexture("stair3", stair3Texture);

  sf::Texture *backgroundTexture = new sf::Texture();
  if (!backgroundTexture->loadFromFile("assets/background/mainMenuBackground.png"))
    cerr << "Error loading mainmenu background texture" << endl;
  InsertTexture("backgroundTexture", backgroundTexture);

  sf::Texture *platform = new sf::Texture();
  if (!platform->loadFromFile("assets/background/air_platform.png"))
    cerr << "Error loading platform texture" << endl;
  InsertTexture("platform", platform);

  sf::Texture *projectile = new sf::Texture();
  if (!projectile->loadFromFile("assets/background/projectile.png"))
    cerr << "Error loading pojectile" << endl;
  InsertTexture("projectile", projectile);
}
