#include "GraphicManager.h"
#include "Level.h"

GraphicManager::GraphicManager()
{
  window = new sf::RenderWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  view = new sf::View(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  playerOne = NULL;

  LoadTexture();
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::ResizeView()
{
  float aspectRatio = float(window->getSize().x / float(window->getSize().y));
  view->setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void GraphicManager::SetViewCenter()
{
  // code to set the view to not extrapolate the level limits borders
  sf::Vector2f viewCenter = playerOne->GetPosition();

  // set in Y
  if (viewCenter.y + (view->getSize().y / 2.0f) >= static_cast<float>(window->getSize().y))
    viewCenter.y = static_cast<float>(window->getSize().y) - (view->getSize().y / 2.0f);
  if (viewCenter.y - (view->getSize().y / 2.0f) <= 0.0f)
    viewCenter.y = (view->getSize().y / 2.0f);

  // set in X
  if (viewCenter.x - (view->getSize().x / 2.0f) <= 0.0f)
    viewCenter.x = view->getSize().x / 2.0f;
  if (viewCenter.x + (view->getSize().x / 2.0f) >= currentLevel->GetSizeX())
    viewCenter.x = currentLevel->GetSizeX() - (view->getSize().x / 2.0f);

  view->setCenter(viewCenter);
  window->setView(*view);
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

  sf::Texture *enemyMeleeTexture = new sf::Texture();
  if (!enemyMeleeTexture->loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    cerr << "Error loading enemyMeleeTexture texture" << endl;
  InsertTexture("enemyMelee", enemyMeleeTexture);

  sf::Texture *playerOneTexture = new sf::Texture();
  if (!playerOneTexture->loadFromFile("assets/characters/PlayerOne/playerV2.png"))
    cerr << "Error loading playerOneTexture texture" << endl;
  InsertTexture("playerOne", playerOneTexture);

  sf::Texture *sewerBackgroundTexture = new sf::Texture();
  if (!sewerBackgroundTexture->loadFromFile("assets/background/levelOne.png"))
    cerr << "Erro loading backgroundTexture" << endl;
  InsertTexture("levelOne", sewerBackgroundTexture);
}

void GraphicManager::Draw()
{
  currentLevel->Draw(*window);
}