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
  delete(window);
  delete(view);

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
  sf::Texture *basePlataformTexture = new sf::Texture();
  if (!basePlataformTexture->loadFromFile("assets/background/Plataforms/teste.png"))
    cerr << "Error loading platform texture" << endl;
  InsertTexture("basePlataformTexture", basePlataformTexture);

  sf::Texture *spikesTexture = new sf::Texture();
  if (!spikesTexture->loadFromFile("assets/background/spikes.png"))
    cerr << "Erro loading spikes texture" << endl;
  InsertTexture("spikesTexture", spikesTexture);

  sf::Texture *sewerBackground = new sf::Texture();
  if (!sewerBackground->loadFromFile("assets/background/levelOne.png"))
    cerr << "Erro loading sewerBackground texture" << endl;
  InsertTexture("LevelSewerBackground", sewerBackground);

  sf::Texture *enemyMeleeTexture = new sf::Texture();
  if (!enemyMeleeTexture->loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    cerr << "Error loading enemyMeleeTexture texture" << endl;
  InsertTexture("enemyMelee", enemyMeleeTexture);

  sf::Texture *enemyShooterTexture = new sf::Texture();
  if (!enemyShooterTexture->loadFromFile("assets/characters/EnemyShooter/enemy_shooter.png"))
    cerr << "Error loading enemyShooterTexture texture" << endl;
  InsertTexture("enemyShooter", enemyShooterTexture);

  sf::Texture *playerOneTexture = new sf::Texture();
  if (!playerOneTexture->loadFromFile("assets/characters/PlayerOne/playerV2.png"))
    cerr << "Error loading playerOneTexture texture" << endl;
  InsertTexture("playerOne", playerOneTexture);

  sf::Texture *sewerBackgroundTexture = new sf::Texture();
  if (!sewerBackgroundTexture->loadFromFile("assets/background/levelOne.png"))
    cerr << "Erro loading sewrbackgroundTexture" << endl;
  InsertTexture("levelOne", sewerBackgroundTexture);

  sf::Texture *backgroundTexture = new sf::Texture();
  if(!backgroundTexture->loadFromFile("assets/background/mainMenuBackground.png"));
    cerr << "Error loading mainmenu background texture"<<endl;
  InsertTexture("backgroundTexture", backgroundTexture);

  sf::Texture* platform = new sf::Texture();
  if(!platform->loadFromFile("assets/background/air_platform.png"))
    cerr <<"Error loading platform texture"<<endl;
  InsertTexture("platform", platform);

  sf::Texture* projectile = new sf::Texture();
  if(!projectile->loadFromFile("assets/background/projectile.png"))
    cerr << "Error loading pojectile" <<endl;
  InsertTexture("projectile", projectile);
}
