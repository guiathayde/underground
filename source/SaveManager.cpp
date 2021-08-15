#include "SaveManager.h"
#include "Level.h"
#include "Item.h"
#include "Ranking.h"
#include "Enemy.h"
#include "DynamicEntity.h"
#include "ChildPlayerOne.h"
#include "ChildPlayerTwo.h"
#include "HollowHatEnemy.h"
#include "TrashMonster.h"
#include "WelderEnemy.h"
#include "GraphicManager.h"
#include "AirPlatform.h"
#include "BasePlatform.h"
#include "TrapPlatform.h"
#include "WallPlatform.h"
#include "Spike.h"
#include "Door.h"
#include "Stair.h"

SaveManager::SaveManager(GraphicManager *graphicManager, Ranking *ranking)
{
  currentGraphicManager = graphicManager;
  currentLevel = NULL;
  currentRanking = ranking;
}

SaveManager::~SaveManager()
{
  delete currentGraphicManager;
  delete currentLevel;
  delete currentRanking;
}

void SaveManager::SaveLevel()
{
  ofstream Writer("data/saves/level.txt", ios::out);
  Writer << currentLevel->GetNameLevel() << endl;
  Writer.close();

  SaveCharacters();
  SaveObstacles();
  SaveItems();
}

void SaveManager::SaveCharacters(){
  
  ofstream Writer("data/saves/characters.txt", ios::out);

  if (!Writer)
    cerr << "File characters.txt cannot be opened" << endl;

  list<Character*>::iterator itCharacter;

  for (itCharacter = currentLevel->GetListCharacters()->begin(); itCharacter != currentLevel->GetListCharacters()->end(); itCharacter++)
  {
    Writer << (*itCharacter)->GetId() << " "
           << (*itCharacter)->GetPosition().x << " "
           << (*itCharacter)->GetPosition().y << " "
           << (*itCharacter)->GetHearts() << endl;
  }

  Writer.close();
}

void SaveManager::ReadCharacters()
{
  ChildPlayerOne *playerOne;
  ChildPlayerTwo *playerTwo;
  HollowHatEnemy *hollowHat;
  TrashMonster *trashMonster;
  WelderEnemy *welder;

  ifstream Reader("data/saves/characters.txt", ios::in);

  if (Reader)
  {
    while (!Reader.eof())
    {
      int id, hearts;
      float x, y;

      Reader >> id >> x >> y >> hearts;

      switch (id)
      {
      case 1:
        playerOne = new ChildPlayerOne(currentGraphicManager, sf::Vector2f(x, y));
        playerOne->SetHearts(hearts);
        currentLevel->SetPlayerOne(playerOne);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(playerOne);
        currentLevel->GetListCharacters()->push_back(playerOne);
        break;
        
      case 2:
        playerTwo = new ChildPlayerTwo(currentGraphicManager, sf::Vector2f(x, y));
        playerTwo->SetHearts(hearts);
        currentLevel->SetPlayerTwo(playerTwo);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(playerTwo);
        currentLevel->GetListCharacters()->push_back(playerTwo);
        break;

      case 3:
        hollowHat = new HollowHatEnemy(currentGraphicManager, sf::Vector2f(x, y));
        hollowHat->SetHearts(hearts);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(hollowHat);
        currentLevel->GetListCharacters()->push_back(hollowHat);
        break;

      case 4:
        trashMonster = new TrashMonster(currentGraphicManager, sf::Vector2f(x, y));
        trashMonster->SetHearts(hearts);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(trashMonster);
        currentLevel->GetListCharacters()->push_back(trashMonster);
        break;

      case 5:
        welder = new WelderEnemy(currentGraphicManager, sf::Vector2f(x, y), currentLevel->GetDynamicEntityList());
        welder->SetHearts(hearts);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(welder);
        currentLevel->GetListCharacters()->push_back(welder);
        break;

      default:
        break;
      }
    }

    Reader.close();
  }
  else
  {
    cerr << "File ranking.txt cannot be opened" << endl;
    Reader.close();
  }
}

void SaveManager::SaveObstacles()
{
  ofstream Writer("data/saves/obstacles.txt", ios::out);

  if (!Writer)
    cerr << "File obstacles.txt cannot be opened" << endl;

  list<Obstacle *>::iterator itObstacle;
  for (itObstacle = currentLevel->GetListObstacles()->begin(); itObstacle != currentLevel->GetListObstacles()->end(); itObstacle++)
  {
    Writer << (*itObstacle)->GetId() << " "
           << (*itObstacle)->GetPosition().x << " "
           << (*itObstacle)->GetPosition().y << " "
           << endl;
  }

  Writer.close();
}

void SaveManager::ReadObstacles()
{
  AirPlatform* airPlatform;
  BasePlatform *basePlatform;
  TrapPlatform *trapPlatform;
  WallPlatform* wallPlatform;

  Spike* spikes;
  Stair* stair;
  Door* doors;

  ifstream Reader("data/saves/obstacles.txt", ios::in);

  if (Reader)
  {
    while (!Reader.eof())
    {
      int id ;
      float x, y;

      Reader >> id >> x >> y;

      switch (id)
      {
        case 6:
        airPlatform = new AirPlatform(currentGraphicManager, sf::Vector2f(x, y));
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(airPlatform);
        currentLevel->GetListObstacles()->push_back(airPlatform);
        break;
      
      case 8:
        trapPlatform = new TrapPlatform(currentGraphicManager, sf::Vector2f(x, y));
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(trapPlatform);
        currentLevel->GetListObstacles()->push_back(trapPlatform);
      
      case 9:
        wallPlatform = new WallPlatform(currentGraphicManager, sf::Vector2f(x, y));
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(wallPlatform);
        currentLevel->GetListObstacles()->push_back(wallPlatform);
      
      
      case 10:
        spikes = new Spike(currentGraphicManager, sf::Vector2f(x, y));
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(spikes);     

      default:
        break;
      }
    }

    Reader.close();
  }
  else
  {
    cerr << "File ranking.txt cannot be opened" << endl;
    Reader.close();
  }
}

void SaveManager::SaveItems(){
  
  ofstream Writer("data/saves/items.txt", ios::out);

  if (!Writer)
    cerr << "File items.txt cannot be opened" << endl;

  list<Item*>::iterator itItem;

  for (itItem = currentLevel->GetListItems()->begin(); itItem != currentLevel->GetListItems()->end(); itItem++)
  {
    Writer << (*itItem)->GetId() << " "
           << (*itItem)->GetPosition().x << " "
           << (*itItem)->GetPosition().y << " "
           << (*itItem)->GetNumber() << " "
           << (*itItem)->GetCaught() << endl;
  }

  Writer.close();
}

void SaveManager::ReadItems()
{
  Stair *stair;
  Door *door;

  ifstream Reader("data/saves/items.txt", ios::in);

  if (Reader)
  {
    while (!Reader.eof())
    {
      int id, number;
      float x, y;
      bool isCought;

      Reader >> id >> x >> y >> number >> isCought;

      switch (id)
      {
      case 11:
        door = new Door(currentGraphicManager, sf::Vector2f(x, y));
        door->SetCaught(isCought);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(stair);
        currentLevel->GetListItems()->push_back(stair);
        break;

      case 12:
        stair = new Stair(currentGraphicManager, sf::Vector2f(x, y), number);
        stair->SetCaught(isCought);
        currentLevel->GetDynamicEntityList()->InsertDynamicEntity(stair);
        currentLevel->GetListItems()->push_back(stair);
        break;

      default:
        break;
      }
    }

    Reader.close();
  }
  else
  {
    cerr << "File ranking.txt cannot be opened" << endl;
    Reader.close();
  }
}

void SaveManager::ReadLevel()
{
  ifstream Reader("data/saves/level.txt", ios::in);
  Reader >> nameLevel;
  Reader.close();

  ReadCharacters();
  ReadObstacles();
  ReadItems();
}

void SaveManager::SaveScore()
{
  ofstream Writer("data/saves/ranking.txt", ios::out);

  if (!Writer)
    cerr << "File ranking.txt cannot be opened" << endl;

  map<string, int>::iterator itRank;
  for (itRank = currentRanking->GetRank()->begin(); itRank != currentRanking->GetRank()->end(); itRank++)
  {
    Writer << itRank->first << " "
           << itRank->second << " "
           << endl;
  }

  Writer.close();
}

void SaveManager::ReadRanking()
{
  ifstream Reader("data/saves/ranking.txt", ios::in);

  if (Reader)
  {
    while (!Reader.eof())
    {
      string name;
      int score;

      Reader >> name >> score;

      if (!name.empty() && score)
        currentRanking->SetRank(name, score);
    }

    Reader.close();
  }
  else
  {
    cerr << "File ranking.txt cannot be opened" << endl;
    Reader.close();
  }
}