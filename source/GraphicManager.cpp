#include "GraphicManager.h"

GraphicManager::GraphicManager()
{
  window = new sf::RenderWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  view = new sf::View(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  mainMenu = new MainMenu(window->getSize().x, window->getSize().y);
  pauseMenu = new PauseMenu(window->getSize().x, window->getSize().y);
  playerOne = NULL;
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
}

void GraphicManager::InsertTexture(const char *name, sf::Texture *texture)
{
  textures.insert(pair<const char *, sf::Texture *>(name, texture));
}

sf::Texture *GraphicManager::GetTexture(const char *name)
{
  map<const char *, sf::Texture *>::iterator itr = textures.find(name);

  return itr->second;
}

void GraphicManager::LoadTexture()
{
  static sf::Texture basePlataformTexture;
  if (!basePlataformTexture.loadFromFile("assets/background/Plataforms/teste.png"))
    cerr << "Error loading platform texture" << endl;
  InsertTexture("basePlataformTexture", &basePlataformTexture);

  static sf::Texture spikesTexture;
  if (!spikesTexture.loadFromFile("assets/background/spikes.png"))
    cerr << "Erro loading spikes texture" << endl;
  InsertTexture("spikesTexture", &spikesTexture);

  static sf::Texture sewerBackground;
  if (!sewerBackground.loadFromFile("assets/background/levelOne.png"))
    cerr << "Erro loading sewerBackground texture" << endl;
  InsertTexture("LevelSewerBackground", &sewerBackground);

  static sf::Texture enemyMeleeTexture;
  if (!enemyMeleeTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
    cerr << "Error loading enemyMeleeTexture texture" << endl;
  InsertTexture("enemyMelee", &enemyMeleeTexture);

  static sf::Texture playerOneTexture;
  if (!playerOneTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png"))
    cerr << "Error loading playerOneTexture texture" << endl;
  InsertTexture("playerOne", &playerOneTexture);
}

void GraphicManager::Draw()
{
  currentLevel->Draw(*window);
}